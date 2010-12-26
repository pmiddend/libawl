#cmake_policy(SET CMP0003 NEW)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

#cmake_policy(SET CMP0003 NEW)
PROJECT (libawl)
#cmake_policy(SET CMP0003 NEW)


SET (CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

IF(${CMAKE_BINARY_DIR} STREQUAL ${CMAKE_SOURCE_DIR})
	message(FATAL_ERROR "In-source builds are not permitted. Make a separate folder for building:\nmkdir build; cd build; cmake ..\nBefore that, remove the files that cmake just created:\nrm -rf CMakeCache.txt CMakeFiles")
ENDIF()

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

LINK_DIRECTORIES(${FCPPT_LIBRARY_DIRS})
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
	ADD_AWL_CPP_GROUP(src/backends/x11/glx)
	ADD_AWL_CPP_GROUP(src/backends/x11/system)
	ADD_AWL_CPP_GROUP(src/backends/x11/system/event)
	ADD_AWL_CPP_GROUP(src/backends/x11/window)
	ADD_AWL_CPP_GROUP(src/backends/x11/window/event)
	ADD_AWL_CPP_GROUP(src/backends/x11/window/event/signal)

	ADD_AWL_HEADER_GROUP(include/awl/backends/x11)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/glx)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/system)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/system/event)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/window)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/window/event)
	ADD_AWL_HEADER_GROUP(include/awl/backends/x11/window/event/signal)
ENDIF()

IF(ENABLE_WINELIB OR AWL_WINDOWS_BACKEND)
	ADD_AWL_CPP_GROUP(src/backends/windows)
	ADD_AWL_CPP_GROUP(src/backends/windows/system)
	ADD_AWL_CPP_GROUP(src/backends/windows/system/event)
	ADD_AWL_CPP_GROUP(src/backends/windows/window)
	ADD_AWL_CPP_GROUP(src/backends/windows/window/event)

	ADD_AWL_HEADER_GROUP(include/awl/backends/windows)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/system)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/system/event)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/window)
	ADD_AWL_HEADER_GROUP(include/awl/backends/windows/window/event)
ENDIF()

ADD_LIBRARY(awl SHARED ${LIBAWLFILES})

TARGET_LINK_LIBRARIES(
	awl
	${Boost_SYSTEM_LIBRARY}
	${Boost_THREAD_LIBRARY}
	${FCPPT_LIBRARIES}
)

IF(AWL_X11_BACKEND)
	INCLUDE_DIRECTORIES(
		${X11_INCLUDE_PATH}
	)

	TARGET_LINK_LIBRARIES(
		awl
		${X11_X11_LIB}
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

IF(UNIX)
	TARGET_LINK_LIBRARIES(
		awl
		pthread
	)
ENDIF()

IF(ENABLE_OPENGL)
	TARGET_LINK_LIBRARIES(
		awl
		${OPENGL_gl_LIBRARY}
	)
ENDIF()

ADD_SUBDIRECTORY(examples)

INSTALL(
	TARGETS awl	
	DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
)

INSTALL(
	DIRECTORY include/
	DESTINATION include
)

INSTALL(
	FILES ${CMAKE_BINARY_DIR}/include/awl/config.hpp
	DESTINATION include/awl
)
