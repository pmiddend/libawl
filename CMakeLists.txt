cmake_minimum_required(
	VERSION 2.6
)

project(
	awl
)

set(
	CMAKE_MODULE_PATH
	"${CMAKE_SOURCE_DIR}/CMakeModules;${CMAKE_MODULE_PATH}"
)

include(
	FcpptCMakeUtils
)

include(
	FcpptSymbol
)

include_directories(
	${CMAKE_SOURCE_DIR}/include
)

# Boost begin
find_package(
	Boost 1.47.0 REQUIRED
	chrono
	system
)

include_directories(
	${FCPPT_UTILS_INCLUDE_SYSTEM}
	${Boost_INCLUDE_DIRS}
)

link_directories(
	${Boost_LIBRARY_DIRS}
)

# Boost end

# Fcppt begin
find_package(
	fcppt
	REQUIRED
)

add_definitions(
	"${fcppt_DEFINITIONS}"
)

include_directories(
	${fcppt_INCLUDE_DIRS}
)

# Fcppt end

# Source groups end

add_definitions(
	-D BOOST_ASIO_SEPARATE_COMPILATION
)

SET(
	AWL_BASE_SRC_FILES
	src/create_log.cpp
	src/cursor/create_predefined.cpp
	src/cursor/object.cpp
	src/event/create_processor.cpp
	src/event/processor.cpp
	src/event/scoped_window_processor.cpp
	src/exception.cpp
	src/log.cpp
	src/log_context.cpp
	src/log_location.cpp
	src/main/exit_failure.cpp
	src/main/exit_success.cpp
	src/main/function_context.cpp
	src/system/create.cpp
	src/system/event/create_processor.cpp
	src/system/event/processor.cpp
	src/system/event/quit.cpp
	src/system/object.cpp
	src/visual/object.cpp
	src/window/event/create_processor.cpp
	src/window/event/processor.cpp
	src/window/event/resize.cpp
	src/window/has_focus.cpp
	src/window/object.cpp
	src/window/parameters.cpp
)

SET(
	AWL_BASE_INCLUDE_FILES
	include/awl/class_symbol.hpp
	include/awl/create_log.hpp
	include/awl/cursor/const_optional_object_ref.hpp
	include/awl/cursor/const_optional_object_ref_fwd.hpp
	include/awl/cursor/create_predefined.hpp
	include/awl/cursor/object.hpp
	include/awl/cursor/object_fwd.hpp
	include/awl/cursor/object_scoped_ptr.hpp
	include/awl/cursor/object_unique_ptr.hpp
	include/awl/cursor/predefined.hpp
	include/awl/event/create_processor.hpp
	include/awl/event/processor.hpp
	include/awl/event/processor_fwd.hpp
	include/awl/event/processor_scoped_ptr.hpp
	include/awl/event/processor_shared_ptr.hpp
	include/awl/event/processor_unique_ptr.hpp
	include/awl/event/scoped_window_processor.hpp
	include/awl/event/scoped_window_processor_fwd.hpp
	include/awl/exception.hpp
	include/awl/log.hpp
	include/awl/log_context.hpp
	include/awl/log_location.hpp
	include/awl/main/exit_code.hpp
	include/awl/main/exit_failure.hpp
	include/awl/main/exit_success.hpp
	include/awl/main/function_context.hpp
	include/awl/main/function_context_fwd.hpp
	include/awl/system/create.hpp
	include/awl/system/event/create_processor.hpp
	include/awl/system/event/optional_processor_ref.hpp
	include/awl/system/event/processor.hpp
	include/awl/system/event/processor_fwd.hpp
	include/awl/system/event/processor_scoped_ptr.hpp
	include/awl/system/event/processor_shared_ptr.hpp
	include/awl/system/event/processor_unique_ptr.hpp
	include/awl/system/event/quit.hpp
	include/awl/system/event/quit_callback.hpp
	include/awl/system/event/quit_function.hpp
	include/awl/system/event/quit_fwd.hpp
	include/awl/system/event/quit_signal.hpp
	include/awl/system/object.hpp
	include/awl/system/object_fwd.hpp
	include/awl/system/object_scoped_ptr.hpp
	include/awl/system/object_shared_ptr.hpp
	include/awl/system/object_unique_ptr.hpp
	include/awl/system/optional_exit_code.hpp
	include/awl/system/optional_exit_code_fwd.hpp
	include/awl/visual/object.hpp
	include/awl/visual/object_fwd.hpp
	include/awl/visual/object_scoped_ptr.hpp
	include/awl/visual/object_unique_ptr.hpp
	include/awl/window/dim.hpp
	include/awl/window/dim_fwd.hpp
	include/awl/window/event/close.hpp
	include/awl/window/event/close_callback.hpp
	include/awl/window/event/close_callback_fwd.hpp
	include/awl/window/event/close_function.hpp
	include/awl/window/event/close_fwd.hpp
	include/awl/window/event/close_signal.hpp
	include/awl/window/event/create_processor.hpp
	include/awl/window/event/destroy.hpp
	include/awl/window/event/destroy_callback.hpp
	include/awl/window/event/destroy_callback_fwd.hpp
	include/awl/window/event/destroy_function.hpp
	include/awl/window/event/destroy_fwd.hpp
	include/awl/window/event/destroy_signal.hpp
	include/awl/window/event/focus_in.hpp
	include/awl/window/event/focus_in_callback.hpp
	include/awl/window/event/focus_in_callback_fwd.hpp
	include/awl/window/event/focus_in_function.hpp
	include/awl/window/event/focus_in_fwd.hpp
	include/awl/window/event/focus_in_signal.hpp
	include/awl/window/event/focus_out.hpp
	include/awl/window/event/focus_out_callback.hpp
	include/awl/window/event/focus_out_callback_fwd.hpp
	include/awl/window/event/focus_out_function.hpp
	include/awl/window/event/focus_out_fwd.hpp
	include/awl/window/event/focus_out_signal.hpp
	include/awl/window/event/hide.hpp
	include/awl/window/event/hide_callback.hpp
	include/awl/window/event/hide_callback_fwd.hpp
	include/awl/window/event/hide_function.hpp
	include/awl/window/event/hide_fwd.hpp
	include/awl/window/event/hide_signal.hpp
	include/awl/window/event/processor.hpp
	include/awl/window/event/processor_fwd.hpp
	include/awl/window/event/processor_scoped_ptr.hpp
	include/awl/window/event/processor_shared_ptr.hpp
	include/awl/window/event/processor_unique_ptr.hpp
	include/awl/window/event/resize.hpp
	include/awl/window/event/resize_callback.hpp
	include/awl/window/event/resize_callback_fwd.hpp
	include/awl/window/event/resize_function.hpp
	include/awl/window/event/resize_fwd.hpp
	include/awl/window/event/resize_signal.hpp
	include/awl/window/event/show.hpp
	include/awl/window/event/show_callback.hpp
	include/awl/window/event/show_callback_fwd.hpp
	include/awl/window/event/show_function.hpp
	include/awl/window/event/show_fwd.hpp
	include/awl/window/event/show_signal.hpp
	include/awl/window/has_focus.hpp
	include/awl/window/object.hpp
	include/awl/window/object_fwd.hpp
	include/awl/window/object_scoped_ptr.hpp
	include/awl/window/object_shared_ptr.hpp
	include/awl/window/object_unique_ptr.hpp
	include/awl/window/optional_dim.hpp
	include/awl/window/optional_dim_fwd.hpp
	include/awl/window/optional_position.hpp
	include/awl/window/optional_position_fwd.hpp
	include/awl/window/parameters.hpp
	include/awl/window/parameters_fwd.hpp
	include/awl/window/scalar.hpp
	include/awl/window/vector.hpp
	include/awl/window/vector_fwd.hpp
)

# We can use either X11 or plain windows or Apple
if(
	APPLE
)
	set(
		AWL_COCOA_BACKEND
		TRUE
	)
elseif(
	UNIX
)
	find_package(
		X11
		REQUIRED
	)

	set(
		AWL_X11_BACKEND
		TRUE
	)
elseif(
	WIN32
)
	set(
		AWL_WINDOWS_BACKEND
		TRUE
	)

	# TODO: actually check what we need here
	add_definitions(
		-D UNICODE -D _UNICODE
	)
	# TODO: Find windows.h, etc.
else()
	message(
		FATAL_ERROR
		"This configuration is not supported!"
	)
endif()

if(
	${CMAKE_SYSTEM_NAME} STREQUAL "Linux"
)
	set(
		AWL_LINUX_BACKEND
		TRUE
	)
endif()

configure_file(
	${CMAKE_SOURCE_DIR}/config.hpp.in
	${CMAKE_BINARY_DIR}/include/awl/config.hpp
)

fcppt_generate_symbol_header(
	AWL_STATIC_LINK
	awl
	AWL
	awl
)

include_directories(
	${CMAKE_BINARY_DIR}/include
)

set(
	AWL_COCOA_SRC_FILES
	src/backends/cocoa/event/create_processor.mm
	src/backends/cocoa/event/processor.mm
	src/backends/cocoa/from_fcppt_string.mm
	src/backends/cocoa/system/create.mm
	src/backends/cocoa/system/event/create_processor.mm
	src/backends/cocoa/system/event/processor.mm
	src/backends/cocoa/system/object.mm
	src/backends/cocoa/window/event/AWLWindowDelegate.mm
	src/backends/cocoa/window/event/create_processor.mm
	src/backends/cocoa/window/event/processor.mm
	src/backends/cocoa/window/instance.mm
)

set(
	AWL_COCOA_INCLUDE_FILES
	include/awl/backends/cocoa/system/create.hpp
	include/awl/backends/cocoa/system/event/create_processor.hpp
	include/awl/backends/cocoa/system/event/optional_processor_ref.hpp
	include/awl/backends/cocoa/system/event/processor.hpp
	include/awl/backends/cocoa/system/event/processor_fwd.hpp
	include/awl/backends/cocoa/system/object.hpp
	include/awl/backends/cocoa/system/object_fwd.hpp
	include/awl/backends/cocoa/window/event/AWLWindowDelegate.hpp
	include/awl/backends/cocoa/window/event/create_processor.hpp
	include/awl/backends/cocoa/window/event/processor.hpp
	include/awl/backends/cocoa/window/event/processor_fwd.hpp
	include/awl/backends/cocoa/window/object.hpp
	include/awl/backends/cocoa/window/object_fwd.hpp
)

set(
	AWL_X11_SRC_FILES
	src/backends/x11/colormap.cpp
	src/backends/x11/cursor/convert_predefined.cpp
	src/backends/x11/cursor/create_predefined.cpp
	src/backends/x11/cursor/holder.cpp
	src/backends/x11/cursor/load_font.cpp
	src/backends/x11/cursor/object.cpp
	src/backends/x11/default_screen.cpp
	src/backends/x11/display.cpp
	src/backends/x11/display_fd.cpp
	src/backends/x11/event/next.cpp
	src/backends/x11/event/object.cpp
	src/backends/x11/event/pending.cpp
	src/backends/x11/event/processor.cpp
	src/backends/x11/free.cpp
	src/backends/x11/get_input_focus.cpp
	src/backends/x11/intern_atom.cpp
	src/backends/x11/log.cpp
	src/backends/x11/original_display.cpp
	src/backends/x11/system/event/map_key.cpp
	src/backends/x11/system/event/object.cpp
	src/backends/x11/system/event/original_processor.cpp
	src/backends/x11/system/event/processor.cpp
	src/backends/x11/system/object.cpp
	src/backends/x11/system/original_object.cpp
	src/backends/x11/to_x11_bool.cpp
	src/backends/x11/visual/create_info.cpp
	src/backends/x11/visual/default.cpp
	src/backends/x11/visual/object.cpp
	src/backends/x11/visual/wrapped.cpp
	src/backends/x11/window/atoms.cpp
	src/backends/x11/window/attributes.cpp
	src/backends/x11/window/class_hint.cpp
	src/backends/x11/window/common_object.cpp
	src/backends/x11/window/create.cpp
	src/backends/x11/window/event/change_mask.cpp
	src/backends/x11/window/event/filter.cpp
	src/backends/x11/window/event/object.cpp
	src/backends/x11/window/event/original_processor.cpp
	src/backends/x11/window/event/poll_mask.cpp
	src/backends/x11/window/event/poll_type.cpp
	src/backends/x11/window/event/processor.cpp
	src/backends/x11/window/event/send.cpp
	src/backends/x11/window/event/to_mask.cpp
	src/backends/x11/window/event/wm_protocols.cpp
	src/backends/x11/window/hints.cpp
	src/backends/x11/window/holder.cpp
	src/backends/x11/window/object.cpp
	src/backends/x11/window/original_class_hint.cpp
	src/backends/x11/window/original_object.cpp
	src/backends/x11/window/root.cpp
	src/backends/x11/window/set_wm_protocols.cpp
	src/backends/x11/window/size_hints.cpp
	src/backends/x11/window/transient_for_hint.cpp
	src/backends/x11/window/visual.cpp
	src/backends/x11/window/wrapped_class_hint.cpp
	src/backends/x11/window/wrapped_object.cpp
)

set(
	AWL_X11_INCLUDE_FILES
	include/awl/backends/x11/atom.hpp
	include/awl/backends/x11/colormap.hpp
	include/awl/backends/x11/colormap_fwd.hpp
	include/awl/backends/x11/cursor/const_optional_object_ref.hpp
	include/awl/backends/x11/cursor/const_optional_object_ref_fwd.hpp
	include/awl/backends/x11/cursor/convert_predefined.hpp
	include/awl/backends/x11/cursor/create_predefined.hpp
	include/awl/backends/x11/cursor/holder.hpp
	include/awl/backends/x11/cursor/holder_fwd.hpp
	include/awl/backends/x11/cursor/holder_scoped_ptr.hpp
	include/awl/backends/x11/cursor/holder_unique_ptr.hpp
	include/awl/backends/x11/cursor/load_font.hpp
	include/awl/backends/x11/cursor/object.hpp
	include/awl/backends/x11/cursor/object_fwd.hpp
	include/awl/backends/x11/cursor/object_unique_ptr.hpp
	include/awl/backends/x11/cursor/shape.hpp
	include/awl/backends/x11/default_screen.hpp
	include/awl/backends/x11/deleter.hpp
	include/awl/backends/x11/discard.hpp
	include/awl/backends/x11/display.hpp
	include/awl/backends/x11/display_fd.hpp
	include/awl/backends/x11/display_fwd.hpp
	include/awl/backends/x11/event/next.hpp
	include/awl/backends/x11/event/object.hpp
	include/awl/backends/x11/event/object_fwd.hpp
	include/awl/backends/x11/event/pending.hpp
	include/awl/backends/x11/event/processor.hpp
	include/awl/backends/x11/event/processor_fwd.hpp
	include/awl/backends/x11/free.hpp
	include/awl/backends/x11/get_input_focus.hpp
	include/awl/backends/x11/intern_atom.hpp
	include/awl/backends/x11/log.hpp
	include/awl/backends/x11/original_display.hpp
	include/awl/backends/x11/screen.hpp
	include/awl/backends/x11/system/event/callback.hpp
	include/awl/backends/x11/system/event/function.hpp
	include/awl/backends/x11/system/event/map_key.hpp
	include/awl/backends/x11/system/event/object.hpp
	include/awl/backends/x11/system/event/object_fwd.hpp
	include/awl/backends/x11/system/event/opcode.hpp
	include/awl/backends/x11/system/event/optional_processor_ref.hpp
	include/awl/backends/x11/system/event/original_processor.hpp
	include/awl/backends/x11/system/event/processor.hpp
	include/awl/backends/x11/system/event/processor_fwd.hpp
	include/awl/backends/x11/system/event/type.hpp
	include/awl/backends/x11/system/object.hpp
	include/awl/backends/x11/system/object_fwd.hpp
	include/awl/backends/x11/system/original_object.hpp
	include/awl/backends/x11/to_x11_bool.hpp
	include/awl/backends/x11/visual/create_info.hpp
	include/awl/backends/x11/visual/default.hpp
	include/awl/backends/x11/visual/info_scoped_ptr.hpp
	include/awl/backends/x11/visual/info_unique_ptr.hpp
	include/awl/backends/x11/visual/object.hpp
	include/awl/backends/x11/visual/object_fwd.hpp
	include/awl/backends/x11/visual/object_scoped_ptr.hpp
	include/awl/backends/x11/visual/object_unique_ptr.hpp
	include/awl/backends/x11/visual/wrapped.hpp
	include/awl/backends/x11/window/atom_count.hpp
	include/awl/backends/x11/window/atoms.hpp
	include/awl/backends/x11/window/atoms_fwd.hpp
	include/awl/backends/x11/window/attributes.hpp
	include/awl/backends/x11/window/change_wm_protocols.hpp
	include/awl/backends/x11/window/class_hint.hpp
	include/awl/backends/x11/window/class_hint_fwd.hpp
	include/awl/backends/x11/window/common_object.hpp
	include/awl/backends/x11/window/create.hpp
	include/awl/backends/x11/window/event/atom_vector.hpp
	include/awl/backends/x11/window/event/callback.hpp
	include/awl/backends/x11/window/event/change_mask.hpp
	include/awl/backends/x11/window/event/filter.hpp
	include/awl/backends/x11/window/event/function.hpp
	include/awl/backends/x11/window/event/mask.hpp
	include/awl/backends/x11/window/event/object.hpp
	include/awl/backends/x11/window/event/object_fwd.hpp
	include/awl/backends/x11/window/event/optional.hpp
	include/awl/backends/x11/window/event/optional_mask.hpp
	include/awl/backends/x11/window/event/original_processor.hpp
	include/awl/backends/x11/window/event/poll_mask.hpp
	include/awl/backends/x11/window/event/poll_type.hpp
	include/awl/backends/x11/window/event/processor.hpp
	include/awl/backends/x11/window/event/processor_fwd.hpp
	include/awl/backends/x11/window/event/send.hpp
	include/awl/backends/x11/window/event/to_mask.hpp
	include/awl/backends/x11/window/event/type.hpp
	include/awl/backends/x11/window/event/wm_protocols.hpp
	include/awl/backends/x11/window/hints.hpp
	include/awl/backends/x11/window/holder.hpp
	include/awl/backends/x11/window/object.hpp
	include/awl/backends/x11/window/object_fwd.hpp
	include/awl/backends/x11/window/object_scoped_ptr.hpp
	include/awl/backends/x11/window/object_shared_ptr.hpp
	include/awl/backends/x11/window/object_unique_ptr.hpp
	include/awl/backends/x11/window/original_class_hint.hpp
	include/awl/backends/x11/window/original_object.hpp
	include/awl/backends/x11/window/root.hpp
	include/awl/backends/x11/window/set_wm_protocols.hpp
	include/awl/backends/x11/window/size_hints.hpp
	include/awl/backends/x11/window/transient_for_hint.hpp
	include/awl/backends/x11/window/visual.hpp
	include/awl/backends/x11/window/wrapped_class_hint.hpp
	include/awl/backends/x11/window/wrapped_object.hpp
)

set(
	AWL_LINUX_INCLUDE_FILES
	include/awl/backends/linux/fd/callback.hpp
	include/awl/backends/linux/fd/callback_fwd.hpp
	include/awl/backends/linux/fd/duration.hpp
	include/awl/backends/linux/fd/epoll/ctl.hpp
	include/awl/backends/linux/fd/epoll/fd.hpp
	include/awl/backends/linux/fd/epoll/fd_fwd.hpp
	include/awl/backends/linux/fd/epoll/scoped.hpp
	include/awl/backends/linux/fd/epoll/scoped_fwd.hpp
	include/awl/backends/linux/fd/epoll/set.hpp
	include/awl/backends/linux/fd/epoll/set_fwd.hpp
	include/awl/backends/linux/fd/event.hpp
	include/awl/backends/linux/fd/event_fwd.hpp
	include/awl/backends/linux/fd/function.hpp
	include/awl/backends/linux/fd/object.hpp
	include/awl/backends/linux/fd/object_vector.hpp
	include/awl/backends/linux/fd/optional_duration.hpp
	include/awl/backends/linux/fd/optional_duration_fwd.hpp
	include/awl/backends/linux/fd/processor.hpp
	include/awl/backends/linux/fd/processor_fwd.hpp
)

set(
	AWL_LINUX_SRC_FILES
	src/backends/linux/fd/epoll/ctl.cpp
	src/backends/linux/fd/epoll/fd.cpp
	src/backends/linux/fd/epoll/scoped.cpp
	src/backends/linux/fd/epoll/set.cpp
	src/backends/linux/fd/processor.cpp
)

set(
	AWL_WINDOWS_SRC_FILES
	src/backends/windows/counted_wndclass.cpp
	src/backends/windows/cursor/convert_predefined.cpp
	src/backends/windows/cursor/create_predefined.cpp
	src/backends/windows/cursor/load.cpp
	src/backends/windows/cursor/object.cpp
	src/backends/windows/cursor/shared.cpp
	src/backends/windows/default_wnd_proc.cpp
	src/backends/windows/event/get.cpp
	src/backends/windows/event/message.cpp
	src/backends/windows/event/object.cpp
	src/backends/windows/event/peek.cpp
	src/backends/windows/event/post_message.cpp
	src/backends/windows/event/processor.cpp
	src/backends/windows/format_message.cpp
	src/backends/windows/get_focus.cpp
	src/backends/windows/local_free.cpp
	src/backends/windows/module_handle.cpp
	src/backends/windows/scoped_local_memory.cpp
	src/backends/windows/system/event/handle.cpp
	src/backends/windows/system/event/object.cpp
	src/backends/windows/system/event/original_handle.cpp
	src/backends/windows/system/event/original_processor.cpp
	src/backends/windows/system/event/processor.cpp
	src/backends/windows/system/object.cpp
	src/backends/windows/system/original_object.cpp
	src/backends/windows/system_metrics.cpp
	src/backends/windows/visual/null_object.cpp
	src/backends/windows/visual/object.cpp
	src/backends/windows/window/adjusted_size.cpp
	src/backends/windows/window/client_to_screen.cpp
	src/backends/windows/window/common_object.cpp
	src/backends/windows/window/event/combine_result.cpp
	src/backends/windows/window/event/object.cpp
	src/backends/windows/window/event/original_processor.cpp
	src/backends/windows/window/event/processor.cpp
	src/backends/windows/window/event/scoped_user_message.cpp
	src/backends/windows/window/event/wnd_proc.cpp
	src/backends/windows/window/get_client_rect.cpp
	src/backends/windows/window/get_rect.cpp
	src/backends/windows/window/object.cpp
	src/backends/windows/window/original_object.cpp
	src/backends/windows/window/screen_to_client.cpp
	src/backends/windows/window/wrapped_object.cpp
	src/backends/windows/wndclass.cpp
)

set(
	AWL_WINDOWS_INCLUDE_FILES
	include/awl/backends/windows/counted_wndclass.hpp
	include/awl/backends/windows/counted_wndclass_fwd.hpp
	include/awl/backends/windows/cursor/const_optional_object_ref.hpp
	include/awl/backends/windows/cursor/const_optional_object_ref_fwd.hpp
	include/awl/backends/windows/cursor/convert_predefined.hpp
	include/awl/backends/windows/cursor/create_predefined.hpp
	include/awl/backends/windows/cursor/load.hpp
	include/awl/backends/windows/cursor/object.hpp
	include/awl/backends/windows/cursor/object_fwd.hpp
	include/awl/backends/windows/cursor/object_unique_ptr.hpp
	include/awl/backends/windows/cursor/shared.hpp
	include/awl/backends/windows/cursor/shared_fwd.hpp
	include/awl/backends/windows/default_wnd_proc.hpp
	include/awl/backends/windows/event/get.hpp
	include/awl/backends/windows/event/lparam.hpp
	include/awl/backends/windows/event/message.hpp
	include/awl/backends/windows/event/message_fwd.hpp
	include/awl/backends/windows/event/object.hpp
	include/awl/backends/windows/event/object_fwd.hpp
	include/awl/backends/windows/event/optional_message.hpp
	include/awl/backends/windows/event/peek.hpp
	include/awl/backends/windows/event/post_message.hpp
	include/awl/backends/windows/event/processor.hpp
	include/awl/backends/windows/event/processor_fwd.hpp
	include/awl/backends/windows/event/type.hpp
	include/awl/backends/windows/event/wparam.hpp
	include/awl/backends/windows/format_message.hpp
	include/awl/backends/windows/get_focus.hpp
	include/awl/backends/windows/local_free.hpp
	include/awl/backends/windows/module_handle.hpp
	include/awl/backends/windows/optional_point.hpp
	include/awl/backends/windows/optional_point_fwd.hpp
	include/awl/backends/windows/optional_rect.hpp
	include/awl/backends/windows/optional_rect_fwd.hpp
	include/awl/backends/windows/scoped_local_memory.hpp
	include/awl/backends/windows/system/event/callback.hpp
	include/awl/backends/windows/system/event/function.hpp
	include/awl/backends/windows/system/event/handle.hpp
	include/awl/backends/windows/system/event/handle_callback.hpp
	include/awl/backends/windows/system/event/handle_destroy_callback.hpp
	include/awl/backends/windows/system/event/handle_function.hpp
	include/awl/backends/windows/system/event/handle_fwd.hpp
	include/awl/backends/windows/system/event/handle_unique_ptr.hpp
	include/awl/backends/windows/system/event/object.hpp
	include/awl/backends/windows/system/event/object_fwd.hpp
	include/awl/backends/windows/system/event/optional_processor_ref.hpp
	include/awl/backends/windows/system/event/original_handle.hpp
	include/awl/backends/windows/system/event/original_processor.hpp
	include/awl/backends/windows/system/event/original_processor_fwd.hpp
	include/awl/backends/windows/system/event/processor.hpp
	include/awl/backends/windows/system/event/processor_fwd.hpp
	include/awl/backends/windows/system/object.hpp
	include/awl/backends/windows/system/object_fwd.hpp
	include/awl/backends/windows/system/original_object.hpp
	include/awl/backends/windows/system_metrics.hpp
	include/awl/backends/windows/visual/null_object.hpp
	include/awl/backends/windows/visual/object.hpp
	include/awl/backends/windows/visual/object_fwd.hpp
	include/awl/backends/windows/visual/object_scoped_ptr.hpp
	include/awl/backends/windows/visual/object_unique_ptr.hpp
	include/awl/backends/windows/window/adjusted_size.hpp
	include/awl/backends/windows/window/client_to_screen.hpp
	include/awl/backends/windows/window/common_object.hpp
	include/awl/backends/windows/window/event/callback.hpp
	include/awl/backends/windows/window/event/combine_result.hpp
	include/awl/backends/windows/window/event/function.hpp
	include/awl/backends/windows/window/event/object.hpp
	include/awl/backends/windows/window/event/object_fwd.hpp
	include/awl/backends/windows/window/event/original_processor.hpp
	include/awl/backends/windows/window/event/processor.hpp
	include/awl/backends/windows/window/event/processor_fwd.hpp
	include/awl/backends/windows/window/event/return_type.hpp
	include/awl/backends/windows/window/event/return_type_fwd.hpp
	include/awl/backends/windows/window/event/scoped_user_message.hpp
	include/awl/backends/windows/window/event/scoped_user_message_fwd.hpp
	include/awl/backends/windows/window/event/wnd_proc.hpp
	include/awl/backends/windows/window/get_client_rect.hpp
	include/awl/backends/windows/window/get_rect.hpp
	include/awl/backends/windows/window/object.hpp
	include/awl/backends/windows/window/object_fwd.hpp
	include/awl/backends/windows/window/object_scoped_ptr.hpp
	include/awl/backends/windows/window/object_shared_ptr.hpp
	include/awl/backends/windows/window/object_unique_ptr.hpp
	include/awl/backends/windows/window/original_object.hpp
	include/awl/backends/windows/window/screen_to_client.hpp
	include/awl/backends/windows/window/wrapped_object.hpp
	include/awl/backends/windows/windows.hpp
	include/awl/backends/windows/wndclass.hpp
	include/awl/backends/windows/wndclass_fwd.hpp
	include/awl/backends/windows/wndclass_remove_callback.hpp
)

set(
	AWL_INCLUDE_FILES
	"${AWL_BASE_INCLUDE_FILES}"
)

set(
	AWL_SRC_FILES
	"${AWL_BASE_SRC_FILES}"
)

if(
	AWL_COCOA_BACKEND
)
	set(
		AWL_INCLUDE_FILES
		"${AWL_INCLUDE_FILES};${AWL_COCOA_INCLUDE_FILES}"
	)

	set(
		AWL_SRC_FILES
		"${AWL_SRC_FILES};${AWL_COCOA_SRC_FILES}"
	)

	add_definitions(-fobjc-arc)
endif()

if(
	AWL_X11_BACKEND
)
	set(
		AWL_INCLUDE_FILES
		"${AWL_INCLUDE_FILES};${AWL_X11_INCLUDE_FILES}"
	)

	set(
		AWL_SRC_FILES
		"${AWL_SRC_FILES};${AWL_X11_SRC_FILES}"
	)
endif()

if(
	AWL_LINUX_BACKEND
)
	set(
		AWL_INCLUDE_FILES
		"${AWL_INCLUDE_FILES};${AWL_LINUX_INCLUDE_FILES}"
	)

	set(
		AWL_SRC_FILES
		"${AWL_SRC_FILES};${AWL_LINUX_SRC_FILES}"
	)
endif()

if(
	AWL_WINDOWS_BACKEND
)
	set(
		AWL_INCLUDE_FILES
		"${AWL_INCLUDE_FILES};${AWL_WINDOWS_INCLUDE_FILES}"
	)

	set(
		AWL_SRC_FILES
		"${AWL_SRC_FILES};${AWL_WINDOWS_SRC_FILES}"
	)
endif()

set(
	AWL_FILES
	"${AWL_SRC_FILES};${AWL_INCLUDE_FILES}"
)

FCPPT_UTILS_ADD_SOURCE_GROUPS(
	"${AWL_FILES}"
)

option(
	ENABLE_SHARED
	"Build awl as a shared library"
	TRUE
)

option(
	ENABLE_STATIC
	"Build awl as a static library"
	FALSE
)

if(
	NOT ENABLE_SHARED AND NOT ENABLE_STATIC
)
	message(
		FATAL_ERROR
		"You disabled both STATIC and SHARED"
	)
endif()

# choose a library to link the tests to
if(
	ENABLE_SHARED
)
	set(
		AWL_DEFAULT_LINK_TARGET
		awl
	)
endif()

# static overrides shared
if(
	ENABLE_STATIC
)
	set(
		AWL_DEFAULT_LINK_TARGET
		awl_static
	)

	set(
		AWL_CONFIG_LINK_MACROS
		"-D AWL_STATIC_LINK"
	)
endif()

function(
	MAKE_AWL_LIBRARY
	TARGETNAME
	VARIANT
)
	add_library(
		${TARGETNAME}
		${VARIANT}
		${AWL_FILES}
	)

	if(
		NOT MSVC
	)
		target_link_libraries(
			${TARGETNAME}
			${Boost_CHRONO_LIBRARY}
		)
	endif()

	if(
		${VARIANT} STREQUAL "STATIC"
	)
		set_target_properties(
			${TARGETNAME}
			PROPERTIES
			COMPILE_DEFINITIONS
			"AWL_STATIC_LINK"
		)
	endif()

	target_link_libraries(
		${TARGETNAME}
		${fcppt_core_TARGET}
	)

	# TODO: Link to certain windows libs

	if(
		AWL_X11_BACKEND
	)
		target_link_libraries(
			${TARGETNAME}
			${X11_X11_LIB}
		)
	endif()

	if(
		AWL_COCOA_BACKEND
	)
		target_link_libraries(${TARGETNAME} "-framework Cocoa")
	endif()

	fcppt_utils_library_output_path(
		AWL_LIBRARY_DIR
	)

	install(
		TARGETS
		${TARGETNAME}
		DESTINATION
		"${AWL_LIBRARY_DIR}"
		EXPORT
		awlTargets
	)
endfunction()

if(
	ENABLE_STATIC
)
	make_awl_library(
		awl_static
		STATIC
	)
endif()

if(
	ENABLE_SHARED
)
	make_awl_library(
		awl
		SHARED
	)
endif()

if(
	AWL_X11_BACKEND
)
	include_directories(
		${FCPPT_UTILS_INCLUDE_SYSTEM}
		${X11_INCLUDE_PATH}
	)

endif()

option(
	ENABLE_EXAMPLES
	"Build the examples"
	ON
)

if(
	ENABLE_EXAMPLES
)
	add_subdirectory(
		examples
	)
endif()

foreach(
	CUR_FILE
	${AWL_INCLUDE_FILES}
)
	# Cut the filename
	get_filename_component(
		REL_PATH
		${CUR_FILE}
		PATH
	)

	# Replace the leading include/
	string(
		REPLACE
		"include/"
		""
		TRIMMED_PATH
		"${REL_PATH}"
	)

	install(
		FILES
		${CMAKE_SOURCE_DIR}/${CUR_FILE}
		DESTINATION
		${INSTALL_INCLUDE_DIR}/${TRIMMED_PATH}
	)
endforeach()

fcppt_utils_include_path(
	awl_INCLUDE_DIR
)

fcppt_utils_generate_config(
	awl
)

install(
	DIRECTORY
	${CMAKE_BINARY_DIR}/include/
	DESTINATION
	${INSTALL_INCLUDE_DIR}
)

install(
	FILES
	${CMAKE_SOURCE_DIR}/CMakeModules/AwlMainGenerator.cmake
	${CMAKE_SOURCE_DIR}/CMakeModules/FindAwl.cmake
	DESTINATION
	${INSTALL_CMAKEMODULES_DIR}
)

install(
	EXPORT
	awlTargets
	DESTINATION
	${INSTALL_CMAKECONFIG_DIR}
)
