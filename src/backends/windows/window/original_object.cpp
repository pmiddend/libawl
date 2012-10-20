#include <awl/exception.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/cursor/const_optional_object_ref.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#include <awl/backends/windows/visual/object.hpp>
#include <awl/backends/windows/window/adjusted_size.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/static_optional_cast.hpp>
#include <fcppt/text.hpp>


namespace
{

DWORD const window_flags(
	WS_OVERLAPPEDWINDOW
);

}

awl::backends::windows::window::original_object::original_object(
	awl::window::parameters const &_param,
	awl::backends::windows::wndclass &_wndclass,
	awl::backends::windows::wndclass_remove_callback const &_remove_wndclass
)
:
	awl::backends::windows::window::common_object(),
	handle_(
		CreateWindow(
			_wndclass.name().c_str(),
			_param.title().c_str(),
			window_flags,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			awl::backends::windows::window::adjusted_size(
				_param.size(),
				window_flags
			).w(),
			awl::backends::windows::window::adjusted_size(
				_param.size(),
				window_flags
			).h(),
			fcppt::null_ptr(),
			fcppt::null_ptr(),
			awl::backends::windows::module_handle(),
			fcppt::null_ptr()
		)
	),
	remove_wndclass_(
		_remove_wndclass
	),
	cursor_(
		fcppt::static_optional_cast<
			awl::backends::windows::cursor::object const
		>(
			_param.cursor()
		)
	)
{
	if(
		!handle_
	)
		throw awl::exception(
			FCPPT_TEXT("CreateWindow() failed!")
		);

	dynamic_cast<
		awl::backends::windows::visual::object const &
	>(
		_param.visual()
	).apply(
		handle_
	);
}

awl::backends::windows::window::original_object::~original_object()
{
	::DestroyWindow(
		handle_
	);

	remove_wndclass_();
}

HWND
awl::backends::windows::window::original_object::hwnd() const
{
	return handle_;
}

awl::backends::windows::cursor::const_optional_object_ref const
awl::backends::windows::window::original_object::cursor() const
{
	return cursor_;
}
