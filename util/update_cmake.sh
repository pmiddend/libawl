#!/bin/bash

function die()
{
	exit -1
}

function update_main()
{
	local cmakefile="CMakeLists.txt"

	update_cmake \
		"${cmakefile}" \
		$* \
		|| die

	mv "${cmakefile}".new "${cmakefile}" || die
}

update_main \
	AWL_BASE_INCLUDE_FILES \
	-n \
	include/awl \
	-r \
	include/awl/mainloop \
	include/awl/system \
	include/awl/window

update_main \
	AWL_BASE_SRC_FILES \
	-n \
	src \
	-r \
	src/mainloop \
	src/system \
	src/window

update_main \
	AWL_X11_INCLUDE_FILES \
	include/awl/backends/x11

update_main \
	AWL_X11_SRC_FILES \
	-n \
	src/backends/x11 \
	-r \
	src/backends/x11/asio \
	src/backends/x11/system \
	src/backends/x11/window

update_main \
	AWL_X11_OPENGL_SRC_FILES \
	src/backends/x11/glx

update_main \
	AWL_WINDOWS_INCLUDE_FILES \
	include/awl/backends/windows

update_main \
	AWL_WINDOWS_SRC_FILES \
	src/backends/windows

update_main \
	AWL_QUARTZ_INCLUDE_FILES \
	include/awl/backends/quartz

update_main \
	AWL_QUARTZ_SRC_FILES \
	-e '.*\..pp|.*\.mm' \
	src/backends/quartz
