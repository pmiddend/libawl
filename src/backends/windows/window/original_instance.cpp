#include <awl/exception.hpp>
#include <awl/backends/windows/choose_and_set_pixel_format.hpp>
#include <awl/backends/windows/gdi_device.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/event/post_message.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/adjusted_size.hpp>
#include <awl/backends/windows/window/client_rect.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/original_object.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>
#include <fcppt/text.hpp>


namespace
{

DWORD const window_flags(
	WS_OVERLAPPEDWINDOW
);

}

awl::backends::windows::window::original_object::original_object(
	awl::window::parameters const &_param,
	windows::wndclass &_wndclass,
	windows::wndclass_remove_callback const &_remove_wndclass
)
:
	awl::backends::windows::window::object(),
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

awl::backends::windows::window::original_object::~original_object()
{
	::DestroyWindow(
		handle_
	);

	remove_wndclass_();
}

awl::window::dim const
awl::backends::windows::window::original_object::size() const
{
	RECT const rect(
		window::client_rect(
			*this
		)
	);

	return
		awl::window::dim(
			rect.right - rect.left,
			rect.bottom - rect.top
		);
}

HWND
awl::backends::windows::window::original_object::hwnd() const
{
	return handle_;
}

void
awl::backends::windows::window::original_object::show()
{
	BOOL const prev_visible(
		::ShowWindow(
			this->hwnd(),
			SW_SHOWDEFAULT
		)
	);

	if(
		prev_visible != 0
	)
		return;

	awl::window::dim const cur_size(
		this->size()
	);

	windows::event::post_message(
		this->hwnd(),
		fcppt::strong_typedef_construct_cast<
			windows::event::type
		>(
			WM_SIZE
		),
		fcppt::strong_typedef_construct_cast<
			windows::event::wparam
		>(
			SIZE_RESTORED
		),
		windows::event::lparam(
			MAKELPARAM(
				static_cast<
					WORD
				>(
					cur_size.w()
				),
				static_cast<
					WORD
				>(
					cur_size.h()
				)
			)
		)
	);
}
