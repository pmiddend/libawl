# - Try to find the awl library
#
# This module defines the following variables
#
#	AWL_FOUND        - True when awl was found
#	Awl_DEFINITIONS  - Additional compiler flags required
#	Awl_INCLUDE_DIRS - All includes required for awl to work
#	Awl_LIBRARIES    - All libraries required for awl to work
#
# This modules accepts the following variables
#
#	Awl_USE_STATIC_LIBS - Use static linking.
#	Awl_ENABLE_OPENGL   - Use opengl.
#	AWL_INCLUDEDIR      - Hint where the awl includes might be.
#	AWL_LIBRARYDIR      - Hint where the awl libraries might be.

if(
	Awl_FIND_QUIETLY
)
	set(
		AWL_FIND_OPTIONS
		"QUIET"
	)
endif()

if(
	Awl_FIND_REQUIRED
)
	set(
		AWL_FIND_OPTIONS
		"REQUIRED"
	)
endif()

find_package(
	Boost
	1.45.0
	${AWL_FIND_OPTIONS}
)

find_package(
	Fcppt
	${AWL_FIND_OPTIONS}
)

find_path(
	Awl_INCLUDE_DIR
	NAMES awl/config.hpp
	HINTS ${AWL_INCLUDEDIR}
)

macro(
	find_awl_library
	LIBNAME
)
	find_library(
		Awl_LIBRARY
		NAMES ${LIBNAME}
		HINTS ${AWL_LIBRARYDIR}
	)
endmacro()

if(
	Awl_USE_STATIC_LIBS
)
	find_awl_library(
		awl_static
	)

	set(
		Awl_DEFINITIONS
		"-D AWL_STATIC_LINK"
	)
else()
	find_awl_library(
		awl
	)
endif()

set(
	Awl_INCLUDE_DIRS
	"${Awl_INCLUDE_DIR};${Fcppt_INCLUDE_DIRS};${Boost_INCLUDE_DIRS}"
)

set(
	Awl_LIBRARIES
	"${Awl_LIBRARY};${Fcppt_core_LIBRARIES}"
)

if(
	Awl_USE_STATIC_LIBS
)
	if(
		UNIX
	)
		find_package(
			X11
			${AWL_FIND_OPTIONS}
		)

		set(
			Awl_LIBRARIES
			"${Awl_LIBRARIES};${X11_X11_LIB}"
		)
	endif()

	if(
		Awl_ENABLE_OPENGL
	)
		find_package(
			OpenGL
			${AWL_FIND_OPTIONS}
		)

		set(
			Awl_LIBRARIES
			"${Awl_LIBRARIES};${OPENGL_gl_LIBRARY}"
		)
	endif()
endif()

unset(
	AWL_FIND_OPTIONS
)

include(
	FindPackageHandleStandardArgs
)

find_package_Handle_standard_args(
	Awl
	DEFAULT_MSG
	Awl_INCLUDE_DIR
	Awl_LIBRARY
)

mark_as_advanced(
	Awl_INCLUDE_DIR
	Awl_LIBRARY
)
