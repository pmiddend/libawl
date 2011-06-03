# - Try to find the awl library
#
# This module defines the following variables
#
#	AWL_FOUND        - True when awl was found
#	Awl_INCLUDE_DIRS - All includes required for awl to work
#	Awl_LIBRARIES    - All libraries required for awl to work
#
# This modules accepts the following variables
#
#	AWL_INCLUDEDIR    - Hint where the awl includes might be.
#	AWL_LIBRARYDIR    - Hint where the awl libraries might be.

find_package(
	Boost
	${Awl_FIND_REQUIRED}
)

find_package(
	Fcppt
	${Awl_FIND_REQUIRED}
)

find_path(
	Awl_INCLUDE_DIR
	NAMES awl/config.hpp
	HINTS ${AWL_INCLUDEDIR}
)

find_library(
	Awl_LIBRARY
	NAMES awl
	HINTS ${AWL_LIBRARYDIR}
)

include(
	FindPackageHandleStandardArgs
)

set(
	Awl_INCLUDE_DIRS
	${Awl_INCLUDE_DIR};${Fcppt_INCLUDE_DIRS};${Boost_INCLUDE_DIRS}
)

set(
	Awl_LIBRARIES
	${Awl_LIBRARY};${Fcppt_LIBRARIES}
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
