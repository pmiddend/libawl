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
SET (Boost_ADDITIONAL_VERSIONS "1.41" "1.41.0" "1.42" "1.42.0" "1.43" "1.43.0" "1.44" "1.44.0" "1.45" "1.45.0" "1.46" "1.46.0")

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

# Source groups end

ADD_DEFINITIONS(-D BOOST_ASIO_SEPARATE_COMPILATION)

SET(
	AWL_BASE_SRC_FILES
	src/asio.cpp
	src/exception.cpp
	src/log.cpp
	src/log_context.cpp
	src/mainloop/asio/create_io_service.cpp
	src/mainloop/asio/create_io_service_base.cpp
	src/mainloop/asio/io_service.cpp
	src/mainloop/asio/original_io_service.cpp
	src/mainloop/dispatcher.cpp
	src/mainloop/io_service.cpp
	src/system/create.cpp
	src/system/event/create_processor.cpp
	src/system/event/processor.cpp
	src/system/object.cpp
	src/window/event/create_processor.cpp
	src/window/event/processor.cpp
	src/window/event/resize.cpp
	src/window/instance.cpp
	src/window/parameters.cpp
)

SET(
	AWL_BASE_INCLUDE_FILES
	include/awl/class_symbol.hpp
	include/awl/exception.hpp
	include/awl/log.hpp
	include/awl/log_context.hpp
	include/awl/mainloop/asio/create_io_service.hpp
	include/awl/mainloop/asio/create_io_service_base.hpp
	include/awl/mainloop/asio/io_service.hpp
	include/awl/mainloop/asio/io_service_fwd.hpp
	include/awl/mainloop/asio/io_service_ptr.hpp
	include/awl/mainloop/asio/original_io_service.hpp
	include/awl/mainloop/dispatcher.hpp
	include/awl/mainloop/dispatcher_callback.hpp
	include/awl/mainloop/dispatcher_fwd.hpp
	include/awl/mainloop/dispatcher_ptr.hpp
	include/awl/mainloop/io_service.hpp
	include/awl/mainloop/io_service_fwd.hpp
	include/awl/mainloop/io_service_ptr.hpp
	include/awl/mainloop/nullary_callback.hpp
	include/awl/symbol.hpp
	include/awl/system/create.hpp
	include/awl/system/event/create_processor.hpp
	include/awl/system/event/processor.hpp
	include/awl/system/event/processor_fwd.hpp
	include/awl/system/event/processor_ptr.hpp
	include/awl/system/object.hpp
	include/awl/system/object_fwd.hpp
	include/awl/system/object_ptr.hpp
	include/awl/window/bit_depth.hpp
	include/awl/window/depth_buffer.hpp
	include/awl/window/dim.hpp
	include/awl/window/event/create_processor.hpp
	include/awl/window/event/processor.hpp
	include/awl/window/event/processor_fwd.hpp
	include/awl/window/event/processor_ptr.hpp
	include/awl/window/event/resize.hpp
	include/awl/window/event/resize_callback.hpp
	include/awl/window/event/resize_function.hpp
	include/awl/window/event/resize_fwd.hpp
	include/awl/window/instance.hpp
	include/awl/window/instance_fwd.hpp
	include/awl/window/instance_ptr.hpp
	include/awl/window/optional_dim.hpp
	include/awl/window/parameters.hpp
	include/awl/window/parameters_fwd.hpp
	include/awl/window/scalar.hpp
	include/awl/window/stencil_buffer.hpp
	include/awl/window/vector.hpp
)

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

SET(
	AWL_X11_SRC_FILES
	src/backends/x11/asio/dispatcher.cpp
	src/backends/x11/asio/dup.cpp
	src/backends/x11/asio/fcntl.cpp
	src/backends/x11/asio/fd_flags_resetter.cpp
	src/backends/x11/asio/fd_wrapper.cpp
	src/backends/x11/asio/get_fd_flags.cpp
	src/backends/x11/asio/set_fd_flags.cpp
	src/backends/x11/colormap.cpp
	src/backends/x11/display.cpp
	src/backends/x11/display_fd.cpp
	src/backends/x11/free.cpp
	src/backends/x11/glx/create_visual.cpp
	src/backends/x11/glx/create_visual.hpp
	src/backends/x11/glx/create_visual_attributes.cpp
	src/backends/x11/glx/create_visual_attributes.hpp
	src/backends/x11/glx/handle_bit_depth.cpp
	src/backends/x11/glx/handle_bit_depth.hpp
	src/backends/x11/glx/visual_attribute_array.hpp
	src/backends/x11/log.cpp
	src/backends/x11/original_display.cpp
	src/backends/x11/size_hints.cpp
	src/backends/x11/system/event/map_key.cpp
	src/backends/x11/system/event/object.cpp
	src/backends/x11/system/event/original_processor.cpp
	src/backends/x11/system/event/processor.cpp
	src/backends/x11/system/object.cpp
	src/backends/x11/system/original_object.cpp
	src/backends/x11/to_x11_bool.cpp
	src/backends/x11/visual.cpp
	src/backends/x11/window/attributes.cpp
	src/backends/x11/window/class_hint.cpp
	src/backends/x11/window/common_instance.cpp
	src/backends/x11/window/event/change_mask.cpp
	src/backends/x11/window/event/object.cpp
	src/backends/x11/window/event/original_processor.cpp
	src/backends/x11/window/event/poll.cpp
	src/backends/x11/window/event/processor.cpp
	src/backends/x11/window/event/to_mask.cpp
	src/backends/x11/window/hints.cpp
	src/backends/x11/window/instance.cpp
	src/backends/x11/window/original_class_hint.cpp
	src/backends/x11/window/original_instance.cpp
	src/backends/x11/window/root.cpp
	src/backends/x11/window/visual.cpp
	src/backends/x11/window/wrapped_class_hint.cpp
	src/backends/x11/window/wrapped_instance.cpp
)

SET(
	AWL_X11_INCLUDE_FILES
	include/awl/backends/x11/asio/dispatcher.hpp
	include/awl/backends/x11/asio/dup.hpp
	include/awl/backends/x11/asio/fcntl.hpp
	include/awl/backends/x11/asio/fd_flags_resetter.hpp
	include/awl/backends/x11/asio/fd_wrapper.hpp
	include/awl/backends/x11/asio/fd_wrapper_fwd.hpp
	include/awl/backends/x11/asio/get_fd_flags.hpp
	include/awl/backends/x11/asio/read_callback.hpp
	include/awl/backends/x11/asio/set_fd_flags.hpp
	include/awl/backends/x11/colormap.hpp
	include/awl/backends/x11/colormap_fwd.hpp
	include/awl/backends/x11/colormap_ptr.hpp
	include/awl/backends/x11/const_visual_ptr.hpp
	include/awl/backends/x11/deleter.hpp
	include/awl/backends/x11/display.hpp
	include/awl/backends/x11/display_fd.hpp
	include/awl/backends/x11/display_fwd.hpp
	include/awl/backends/x11/display_ptr.hpp
	include/awl/backends/x11/free.hpp
	include/awl/backends/x11/log.hpp
	include/awl/backends/x11/original_display.hpp
	include/awl/backends/x11/screen.hpp
	include/awl/backends/x11/size_hints.hpp
	include/awl/backends/x11/system/event/callback.hpp
	include/awl/backends/x11/system/event/function.hpp
	include/awl/backends/x11/system/event/map_key.hpp
	include/awl/backends/x11/system/event/object.hpp
	include/awl/backends/x11/system/event/object_fwd.hpp
	include/awl/backends/x11/system/event/opcode.hpp
	include/awl/backends/x11/system/event/original_processor.hpp
	include/awl/backends/x11/system/event/processor.hpp
	include/awl/backends/x11/system/event/processor_fwd.hpp
	include/awl/backends/x11/system/event/processor_ptr.hpp
	include/awl/backends/x11/system/event/type.hpp
	include/awl/backends/x11/system/object.hpp
	include/awl/backends/x11/system/object_fwd.hpp
	include/awl/backends/x11/system/object_ptr.hpp
	include/awl/backends/x11/system/original_object.hpp
	include/awl/backends/x11/to_x11_bool.hpp
	include/awl/backends/x11/visual.hpp
	include/awl/backends/x11/visual_fwd.hpp
	include/awl/backends/x11/visual_ptr.hpp
	include/awl/backends/x11/window/attributes.hpp
	include/awl/backends/x11/window/class_hint.hpp
	include/awl/backends/x11/window/class_hint_fwd.hpp
	include/awl/backends/x11/window/class_hint_ptr.hpp
	include/awl/backends/x11/window/common_instance.hpp
	include/awl/backends/x11/window/event/callback.hpp
	include/awl/backends/x11/window/event/change_mask.hpp
	include/awl/backends/x11/window/event/function.hpp
	include/awl/backends/x11/window/event/object.hpp
	include/awl/backends/x11/window/event/object_fwd.hpp
	include/awl/backends/x11/window/event/optional.hpp
	include/awl/backends/x11/window/event/original_processor.hpp
	include/awl/backends/x11/window/event/poll.hpp
	include/awl/backends/x11/window/event/processor.hpp
	include/awl/backends/x11/window/event/processor_fwd.hpp
	include/awl/backends/x11/window/event/processor_ptr.hpp
	include/awl/backends/x11/window/event/to_mask.hpp
	include/awl/backends/x11/window/hints.hpp
	include/awl/backends/x11/window/instance.hpp
	include/awl/backends/x11/window/instance_fwd.hpp
	include/awl/backends/x11/window/instance_ptr.hpp
	include/awl/backends/x11/window/original_class_hint.hpp
	include/awl/backends/x11/window/original_instance.hpp
	include/awl/backends/x11/window/root.hpp
	include/awl/backends/x11/window/visual.hpp
	include/awl/backends/x11/window/wrapped_class_hint.hpp
	include/awl/backends/x11/window/wrapped_instance.hpp
)

SET(
	AWL_WINDOWS_SRC_FILES
	src/backends/windows/asio/dispatcher.cpp
	src/backends/windows/choose_and_set_pixel_format.cpp
	src/backends/windows/counted_wndclass.cpp
	src/backends/windows/default_wnd_proc.cpp
	src/backends/windows/format_message.cpp
	src/backends/windows/gdi_device.cpp
	src/backends/windows/module_handle.cpp
	src/backends/windows/system/event/handle.cpp
	src/backends/windows/system/event/object.cpp
	src/backends/windows/system/event/original_handle.cpp
	src/backends/windows/system/event/original_processor.cpp
	src/backends/windows/system/event/processor.cpp
	src/backends/windows/system/object.cpp
	src/backends/windows/system/original_object.cpp
	src/backends/windows/system_metrics.cpp
	src/backends/windows/window/adjusted_size.cpp
	src/backends/windows/window/client_rect.cpp
	src/backends/windows/window/client_rect_to_screen.cpp
	src/backends/windows/window/client_to_screen.cpp
	src/backends/windows/window/event/combine_result.cpp
	src/backends/windows/window/event/object.cpp
	src/backends/windows/window/event/original_processor.cpp
	src/backends/windows/window/event/processor.cpp
	src/backends/windows/window/event/wnd_proc.cpp
	src/backends/windows/window/instance.cpp
	src/backends/windows/window/original_instance.cpp
	src/backends/windows/window/screen_to_client.cpp
	src/backends/windows/wndclass.cpp
)

SET(
	AWL_WINDOWS_INCLUDE_FILES
	include/awl/backends/windows/asio/dispatcher.hpp
	include/awl/backends/windows/choose_and_set_pixel_format.hpp
	include/awl/backends/windows/counted_wndclass.hpp
	include/awl/backends/windows/counted_wndclass_fwd.hpp
	include/awl/backends/windows/default_wnd_proc.hpp
	include/awl/backends/windows/format_message.hpp
	include/awl/backends/windows/gdi_device.hpp
	include/awl/backends/windows/gdi_device_fwd.hpp
	include/awl/backends/windows/module_handle.hpp
	include/awl/backends/windows/optional_renderer_parameters.hpp
	include/awl/backends/windows/system/event/callback.hpp
	include/awl/backends/windows/system/event/function.hpp
	include/awl/backends/windows/system/event/handle.hpp
	include/awl/backends/windows/system/event/handle_callback.hpp
	include/awl/backends/windows/system/event/handle_destroy_callback.hpp
	include/awl/backends/windows/system/event/handle_function.hpp
	include/awl/backends/windows/system/event/handle_fwd.hpp
	include/awl/backends/windows/system/event/handle_ptr.hpp
	include/awl/backends/windows/system/event/object.hpp
	include/awl/backends/windows/system/event/object_fwd.hpp
	include/awl/backends/windows/system/event/original_handle.hpp
	include/awl/backends/windows/system/event/original_processor.hpp
	include/awl/backends/windows/system/event/original_processor_fwd.hpp
	include/awl/backends/windows/system/event/processor.hpp
	include/awl/backends/windows/system/event/processor_fwd.hpp
	include/awl/backends/windows/system/event/processor_ptr.hpp
	include/awl/backends/windows/system/object.hpp
	include/awl/backends/windows/system/object_fwd.hpp
	include/awl/backends/windows/system/object_ptr.hpp
	include/awl/backends/windows/system/original_object.hpp
	include/awl/backends/windows/system_metrics.hpp
	include/awl/backends/windows/window/adjusted_size.hpp
	include/awl/backends/windows/window/client_rect.hpp
	include/awl/backends/windows/window/client_rect_to_screen.hpp
	include/awl/backends/windows/window/client_to_screen.hpp
	include/awl/backends/windows/window/event/callback.hpp
	include/awl/backends/windows/window/event/combine_result.hpp
	include/awl/backends/windows/window/event/function.hpp
	include/awl/backends/windows/window/event/object.hpp
	include/awl/backends/windows/window/event/object_fwd.hpp
	include/awl/backends/windows/window/event/original_processor.hpp
	include/awl/backends/windows/window/event/processor.hpp
	include/awl/backends/windows/window/event/processor_fwd.hpp
	include/awl/backends/windows/window/event/processor_ptr.hpp
	include/awl/backends/windows/window/event/return_type.hpp
	include/awl/backends/windows/window/event/wnd_proc.hpp
	include/awl/backends/windows/window/instance.hpp
	include/awl/backends/windows/window/instance_fwd.hpp
	include/awl/backends/windows/window/instance_ptr.hpp
	include/awl/backends/windows/window/original_instance.hpp
	include/awl/backends/windows/window/screen_to_client.hpp
	include/awl/backends/windows/windows.hpp
	include/awl/backends/windows/wndclass.hpp
	include/awl/backends/windows/wndclass_fwd.hpp
	include/awl/backends/windows/wndclass_ptr.hpp
	include/awl/backends/windows/wndclass_remove_callback.hpp
)

SET(
	AWL_INCLUDE_FILES
	"${AWL_BASE_INCLUDE_FILES}"
)

SET(
	AWL_SRC_FILES
	"${AWL_BASE_SRC_FILES}"
)

IF(AWL_X11_BACKEND)
	SET(
		AWL_INCLUDE_FILES
		"${AWL_INCLUDE_FILES};${AWL_X11_INCLUDE_FILES}"
	)

	SET(
		AWL_SRC_FILES
		"${AWL_SRC_FILES};${AWL_X11_SRC_FILES}"
	)
ENDIF()

IF(ENABLE_WINELIB OR AWL_WINDOWS_BACKEND)
	SET(
		AWL_INCLUDE_FILES
		"${AWL_INCLUDE_FILES};${AWL_WINDOWS_INCLUDE_FILES}"
	)

	SET(
		AWL_SRC_FILES
		"${AWL_SRC_FILES};${AWL_WINDOWS_SRC_FILES}"
	)
ENDIF()

SET(
	AWL_FILES
	"${AWL_SRC_FILES};${AWL_INCLUDE_FILES}"
)

FOREACH(
	CURFILE
	${AWL_FILES}
)
	GET_FILENAME_COMPONENT(
		REL_PATH
		${CURFILE}
		PATH
	)

	STRING(REPLACE "/" "\\" GROUPFOLDER ${REL_PATH})

	SOURCE_GROUP(
		${GROUPFOLDER}
		FILES
		${CURFILE}
	)
ENDFOREACH()

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
	ADD_LIBRARY (${TARGETNAME} ${VARIANT} ${AWL_FILES})

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

FOREACH(
	CUR_FILE
	${AWL_INCLUDE_FILES}
)
	GET_FILENAME_COMPONENT(
		REL_PATH
		${CUR_FILE}
		PATH
	)

	INSTALL(
		FILES
		${CMAKE_SOURCE_DIR}/${CUR_FILE}
		DESTINATION
		${REL_PATH}
	)
ENDFOREACH()

INSTALL(
	FILES ${CMAKE_BINARY_DIR}/include/awl/config.hpp
	DESTINATION include/awl
)

INSTALL(
	FILES
	${CMAKE_SOURCE_DIR}/FindAWL.cmake
	DESTINATION share/cmake/Modules
)
