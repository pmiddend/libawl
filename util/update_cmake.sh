#!/bin/bash

function die()
{
	echo "failure"

	exit -1
}

function update_main()
{
	local cmakefile="CMakeLists.txt"

	update_cmake \
		"${cmakefile}" \
		"${@:1}" \
		|| die

	mv "${cmakefile}".new "${cmakefile}" || die
}

update_main \
	AWL_BASE_INCLUDE_FILES \
	-n \
	include/awl \
	-r \
	include/awl/event \
	include/awl/main \
	include/awl/system \
	include/awl/window

update_main \
	AWL_BASE_SRC_FILES \
	-n \
	src \
	-r \
	src/event \
	src/main \
	src/system \
	src/window

# Cocoa begin
update_main \
	AWL_COCOA_INCLUDE_FILES \
	include/awl/backends/cocoa/window \
	include/awl/backends/cocoa/system

update_main \
	AWL_COCOA_SRC_FILES \
	-e '.*\.(mm|cpp)?' \
	src/backends/cocoa
# Cocoa end

# X11 begin
update_main \
	AWL_X11_INCLUDE_FILES \
	include/awl/backends/x11

update_main \
	AWL_X11_SRC_FILES \
	-n \
	src/backends/x11 \
	-r \
	src/backends/x11/event \
	src/backends/x11/system \
	src/backends/x11/window

update_main \
	AWL_X11_OPENGL_SRC_FILES \
	src/backends/x11/glx
# X11 end

# Windows begin
update_main \
	AWL_WINDOWS_INCLUDE_FILES \
	include/awl/backends/windows

update_main \
	AWL_WINDOWS_SRC_FILES \
	src/backends/windows
# Windows end
