#include <awl/backends/windows/window/original_instance.hpp>
#include <awl/backends/windows/window/adjusted_size.hpp>
#include <awl/backends/windows/choose_and_set_pixel_format.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/gdi_device.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/window/parameters.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

namespace
{

DWORD const window_flags(
	WS_OVERLAPPEDWINDOW
);

}

awl::backends::windows::window::original_instance::original_instance(
	awl::window::parameters const &_param,
	windows::wndclass &_wndclass,
	windows::wndclass_remove_callback const &_remove_wndclass
)
:
	handle_(
		CreateWindow(
			_wndclass.name().c_str(),
			_param.title().c_str(),
			window_flags,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			windows::window::adjusted_size(
				_param.size(),
				window_flags
			).w(),
			windows::window::adjusted_size(
				_param.size(),
				window_flags
			).h(),
			NULL,
			NULL,
			windows::module_handle(),
			NULL
		)
	),
	remove_wndclass_(
		_remove_wndclass
	)
{
	if(
		!handle_
	)
		throw awl::exception(
			FCPPT_TEXT("CreateWindow() failed!")
		);
	
	if(
		_param.has_opengl()
	)
		windows::choose_and_set_pixel_format(
			windows::gdi_device(
				handle_,
				windows::gdi_device::get_tag()
			),
			PFD_DRAW_TO_WINDOW
			| PFD_SUPPORT_OPENGL
			| PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			_param.bit_depth()
			?
				static_cast<
					BYTE
				>(
					*_param.bit_depth()
				)
			:
				static_cast<
					BYTE
				>(
					32
				),
			_param.depth_buffer()
			?
				static_cast<
					BYTE
				>(
					*_param.depth_buffer()
				)
			:
				static_cast<
					BYTE
				>(
					0
				),
			_param.stencil_buffer()
			?
				static_cast<
					BYTE
				>(
					*_param.stencil_buffer()
				)
			:
				static_cast<
					BYTE
				>(
					0
				)
		);
}

awl::backends::windows::window::original_instance::~original_instance()
{
	::DestroyWindow(
		handle_
	);

	remove_wndclass_();
}

awl::window::dim const
awl::backends::windows::window::original_instance::size() const
{
	RECT rect;

	if(
		::GetClientRect(
			handle_,
			&rect
		)
		== FALSE
	)
		throw awl::exception(
			FCPPT_TEXT("GetWindowRect() failed!")
		);

	return
		awl::window::dim(
			rect.right - rect.left,
			rect.bottom - rect.top
		);
}

HWND
awl::backends::windows::window::original_instance::hwnd() const
{
	return handle_;
}

void
awl::backends::windows::window::original_instance::show()
{
	::ShowWindow(
		hwnd(),
		SW_NORMAL
	);
}
