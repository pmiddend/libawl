CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT (libawl)

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
		"-Woverloaded-virtual -Wnon-virtual-dtor"
		"-Wsign-promo -Wstrict-aliasing=1 -Wold-style-cast"
	)

	SET (CMAKE_CXX_FLAGS_RELEASE "-O3 -fomit-frame-pointer -DNDEBUG")

	# C++ 98 has no long long but boost insists on using it anyway
	ADD_DEFINITIONS ("-Wno-long-long")
ENDIF()

INCLUDE_DIRECTORIES (${CMAKE_SOURCE_DIR}/include)

SET (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
SET (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Boost begin
SET (Boost_ADDITIONAL_VERSIONS "1.44.0")

FIND_PACKAGE(
	Boost 1.44.0 REQUIRED
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

ADD_AWL_CPP_GROUP(src)
ADD_AWL_CPP_GROUP(src/window)
ADD_AWL_CPP_GROUP(src/backends)
ADD_AWL_CPP_GROUP(src/backends/x11)
ADD_AWL_CPP_GROUP(src/backends/x11/glx)
ADD_AWL_HEADER_GROUP(include/)
ADD_AWL_HEADER_GROUP(include/awl)
ADD_AWL_HEADER_GROUP(include/awl/window)
ADD_AWL_HEADER_GROUP(include/awl/backends)
ADD_AWL_HEADER_GROUP(include/awl/backends/x11)

FIND_PACKAGE(X11 REQUIRED)

ADD_LIBRARY(libawl STATIC ${LIBAWLFILES})
TARGET_LINK_LIBRARIES(libawl ${X11_X11_LIB} dl)
TARGET_LINK_LIBRARIES(libawl ${X11_LIBRARIES})
TARGET_LINK_LIBRARIES(libawl fcppt)


ADD_SUBDIRECTORY(examples)
