CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT (libawl)

IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

SET(EXTRA_CMAKE_MODULE_PATH "" CACHE PATH "Extra paths to search for cmake modules")

SET (CMAKE_MODULE_PATH "${EXTRA_CMAKE_MODULE_PATH};${CMAKE_SOURCE_DIR}/CMakeModules")

INCLUDE (CheckCXXSourceRuns)

CHECK_CXX_SOURCE_RUNS(
	"#include <cstdlib>
	int main()
	{
	#ifdef __clang__
		return EXIT_SUCCESS;
	#else
		return EXIT_FAILURE;
	#endif
	}
	"
	COMPILER_IS_CLANGPP
)

IF (CMAKE_COMPILER_IS_GNUCXX OR COMPILER_IS_CLANGPP)
	ADD_DEFINITIONS (
		"-pedantic-errors -Wall -Wextra -Wconversion"
		"-Wfloat-equal -Wredundant-decls -Winit-self"
		"-Woverloaded-virtual -Wnon-virtual-dtor -Wshadow"
		"-Wsign-promo -Wstrict-aliasing=1 -Wold-style-cast"
	)

	ADD_DEFINITIONS(-fvisibility=hidden)

	SET (CMAKE_CXX_FLAGS_RELEASE "-O3 -fomit-frame-pointer -DNDEBUG")

	# C++ 98 has no long long but boost insists on using it anyway
	ADD_DEFINITIONS ("-Wno-long-long")
ELSEIF (MSVC)
	ADD_DEFINITIONS ("/W4 /wd4996 /EHa /D_BIND_TO_CURRENT_VCLIBS_VERSION=1")
	#4996 - unsafe standard C++ functions
ENDIF ()

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/include)

SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# General options begin

OPTION(ENABLE_OPENGL "Enable opengl support" TRUE)

OPTION(ENABLE_WINE "Use winelib if available" FALSE)

# General options end

# Boost begin
IF(MSVC)
	SET(Boost_USE_STATIC_LIBS ON)
ENDIF()

SET (Boost_ADDITIONAL_VERSIONS "1.45.0 1.45")

FIND_PACKAGE(
	Boost 1.45.0 REQUIRED
	system
	thread
)

INCLUDE_DIRECTORIES(SYSTEM ${Boost_INCLUDE_DIR})

LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})

# Boost end

# Fcppt begin
FIND_PACKAGE(
	Fcppt
	REQUIRED
)

INCLUDE_DIRECTORIES(${FCPPT_INCLUDE_DIRS})

# Fcppt end

IF(ENABLE_OPENGL)
	FIND_PACKAGE(
		OpenGL
		REQUIRED
	)

	INCLUDE_DIRECTORIES(${OPENGL_INCLUDE_DIR})

	SET(AWL_HAVE_OPENGL TRUE)
ENDIF()

# Groups begin
MACRO(ADD_AWL_SOURCE_GROUP GROUPPATH PATTERN)
	FILE(GLOB GROUPFILES ${GROUPPATH}/${PATTERN})

	STRING(REPLACE "/" "\\" GROUPFOLDER ${GROUPPATH})

	SOURCE_GROUP(${GROUPFOLDER} FILES ${GROUPFILES})

	SET(LIBAWLFILES ${LIBAWLFILES} ${GROUPFILES})
ENDMACRO()

MACRO(ADD_AWL_HEADER_GROUP GROUPPATH)
	ADD_AWL_SOURCE_GROUP(${GROUPPATH} "*.?pp")
ENDMACRO()

MACRO(ADD_AWL_CPP_GROUP GROUPPATH)
	ADD_AWL_SOURCE_GROUP(${GROUPPATH} "*.?pp")
ENDMACRO()

# Source groups end

ADD_DEFINITIONS(-D BOOST_ASIO_SEPARATE_COMPILATION)

ADD_AWL_CPP_GROUP(src)
ADD_AWL_CPP_GROUP(src/mainloop)
ADD_AWL_CPP_GROUP(src/mainloop/asio)
ADD_AWL_CPP_GROUP(src/system)
ADD_AWL_CPP_GROUP(src/system/event)
ADD_AWL_CPP_GROUP(src/window)
ADD_AWL_CPP_GROUP(src/window/event)
ADD_AWL_CPP_GROUP(src/backends)
ADD_AWL_HEADER_GROUP(include/)
ADD_AWL_HEADER_GROUP(include/awl)
ADD_AWL_HEADER_GROUP(include/awl/mainloop)
ADD_AWL_HEADER_GROUP(include/awl/mainloop/asio)
ADD_AWL_HEADER_GROUP(include/awl/system)
ADD_AWL_HEADER_GROUP(include/awl/system/event)
ADD_AWL_HEADER_GROUP(include/awl/window)
ADD_AWL_HEADER_GROUP(include/awl/window/event)
ADD_AWL_HEADER_GROUP(include/awl/backends)

IF(UNIX)
	SET(CMAKE_SHARED_LINKER_FLAGS -Wl,--no-undefined)
ENDIF()

# We can use either X11, winelib or plain windows
IF(UNIX)
	IF(ENABLE_WINELIB)
		FIND_PACKAGE(
			Wine
			REQUIRED
			COMPONENTS
			user32
			gdi32
		)

		SET(AWL_WINDOWS_BACKEND TRUE)
	ELSE()
		FIND_PACKAGE(X11 REQUIRED)

		SET(AWL_X11_BACKEND TRUE)
	ENDIF()
ELSEIF(WIN32)
	SET(AWL_WINDOWS_BACKEND TRUE)

	# TODO: actually check what we need here
	ADD_DEFINITIONS(-D UNICODE -D _UNICODE)
	# TODO: Find windows.h, etc.
ELSE()
	MESSAGE(
		FATAL_ERROR
		"This configuration is not supported!"
	)
ENDIF()

CONFIGURE_FILE(
	${CMAKE_SOURCE_DIR}/config.hpp.in
	${CMAKE_BINARY_DIR}/include/awl/config.hpp
)

INCLUDE_DIRECTORIES(
	${CMAKE_BINARY_DIR}/include
)

IF(AWL_X11_BACKEND)
	ADD_AWL_CPP_GROUP(src/backends/x11)
	ADD_AWL_CPP_GROUP(src/backends/x11/asio)
	ADD_AWL_CPP_GROUP(src/backends/x11/glx)
	ADD_AWL_CPP_GROUP(src/backends/x11/system)
	ADD_AWL_CPP_GROUP(src/backends/x11/system/event)
	ADD_AWL_CPP_GROUP(src/backends/x11/window)
	ADD_AWL_CPP_GROUP(src/backends/x11/window/event)
	ADD_AWL_CPP_GROUP(src/backends/x11/window/event/signal)

	ADD_AWL_HEADER_GROUP(include/awl/backends/x11)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/asio)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/glx)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/system)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/system/event)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/window)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/window/event)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/window/event/signal)
ENDIF()

IF(ENABLE_WINELIB OR AWL_WINDOWS_BACKEND)
	ADD_AWL_CPP_GROUP(src/backends/windows)
	ADD_AWL_CPP_GROUP(src/backends/windows/asio)
	ADD_AWL_CPP_GROUP(src/backends/windows/system)
	ADD_AWL_CPP_GROUP(src/backends/windows/system/event)
	ADD_AWL_CPP_GROUP(src/backends/windows/window)
	ADD_AWL_CPP_GROUP(src/backends/windows/window/event)

	ADD_AWL_HEADER_GROUP(include/awl/backends/windows)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/asio)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/system)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/system/event)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/window)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/window/event)
ENDIF()

IF (MSVC)
	SET (ENABLE_SHARED_DEFAULT OFF)
	SET (ENABLE_STATIC_DEFAULT ON)
ELSE ()
	SET (ENABLE_SHARED_DEFAULT ON)
	SET (ENABLE_STATIC_DEFAULT OFF)
ENDIF ()

OPTION(ENABLE_SHARED "Build awl as a shared library" ${ENABLE_SHARED_DEFAULT})

OPTION(ENABLE_STATIC "Build awl as a static library" ${ENABLE_STATIC_DEFAULT})

IF(NOT ENABLE_SHARED AND NOT ENABLE_STATIC)
	MESSAGE(FATAL_ERROR "You disabled both STATIC and SHARED")
ENDIF()

# choose a library to link the tests to
IF(ENABLE_SHARED)
	SET(AWL_DEFAULT_LINK_TARGET awl)
ENDIF()

# static overrides shared
IF(ENABLE_STATIC)
	SET(AWL_DEFAULT_LINK_TARGET awl_static)
ENDIF()

IF(MSVC AND ${AWL_DEFAULT_LINK_TARGET} STREQUAL "awl")
	SET (AWL_CONFIG_LINK_MACROS "-D AWL_DYN_LINK")
ENDIF()

MACRO(MAKE_AWL_LIBRARY TARGETNAME VARIANT)
	ADD_LIBRARY (${TARGETNAME} ${VARIANT} ${LIBAWLFILES})

	#rename awl_static into awl for UNIX
	IF(${TARGETNAME} STREQUAL awl_static AND UNIX)
		SET_TARGET_PROPERTIES(
			${TARGETNAME} PROPERTIES OUTPUT_NAME awl 
		)
	ENDIF()

	IF (NOT MSVC)
		TARGET_LINK_LIBRARIES(
			${TARGETNAME}
			${Boost_SYSTEM_LIBRARY}
			${Boost_THREAD_LIBRARY}
		)
	ENDIF ()

	TARGET_LINK_LIBRARIES(
		${TARGETNAME}
		${FCPPT_LIBRARIES}
	)

	IF(AWL_X11_BACKEND)
		TARGET_LINK_LIBRARIES(
			${TARGETNAME}
			${X11_X11_LIB}
		)
	ENDIF()

	IF(UNIX)
		TARGET_LINK_LIBRARIES(
			${TARGETNAME}
			pthread
		)
	ENDIF()

	IF(ENABLE_OPENGL)
		TARGET_LINK_LIBRARIES(
			${TARGETNAME}
			${OPENGL_gl_LIBRARY}
		)
	ENDIF()

	INSTALL(
		TARGETS
		${TARGETNAME}
		DESTINATION
		${CMAKE_INSTALL_PREFIX}/lib
	)
ENDMACRO()

IF(ENABLE_STATIC)
	MAKE_AWL_LIBRARY(awl_static STATIC)
ENDIF()

IF(ENABLE_SHARED)
	MAKE_AWL_LIBRARY(awl SHARED)
ENDIF()

IF(AWL_X11_BACKEND)
	INCLUDE_DIRECTORIES(
		${X11_INCLUDE_PATH}
	)

ENDIF()

IF(ENABLE_WINELIB)
	INCLUDE_DIRECTORIES(
		SYSTEM
		${WINE_INCLUDE_DIR}
	)

	#LINK_DIRECTORIES(
	#	${WINE_DLL_PATH}
	#)

	TARGET_LINK_LIBRARIES(
		awl
		"${WINE_user32_LIBRARY}"
	)
ENDIF()

# TODO: Link to certain windows libs

ADD_SUBDIRECTORY(examples)

INSTALL(
	DIRECTORY include/
	DESTINATION include
)

INSTALL(
	FILES ${CMAKE_BINARY_DIR}/include/awl/config.hpp
	DESTINATION include/awl
)

INSTALL(
	FILES
	${CMAKE_SOURCE_DIR}/FindAWL.cmake
	DESTINATION share/cmake/Modules
)
