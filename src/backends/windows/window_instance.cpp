/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2010 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <awl/backends/windows/window_instance.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <awl/window/parameters.hpp>

awl::backends::windows::window_instance::window_instance(
	awl::window::parameters const &_param,
	windows::wndclass &_wndclass,
	windows::wndclass_remove_callback const &_remove_callback
)
:
	decoration_size(
		decoration_rect::null()
	),
	remove_callback_(
		_remove_callback
	)
{

	DWORD const flags(
		WS_OVERLAPPEDWINDOW
	);

	{
		RECT rect = {};

		if(
			!::AdjustWindowRect(
				&rect,
				flags,
				FALSE
			)
		)
			throw awl::exception(
				FCPPT_TEXT("AdjustWindowRect() failed!")
			);

		decoration_size_ =
			decoration_rect(
				decoration_rect::vector(
					rect.left,
					rect.top
				),
				decoration_rect::dim(
					rect.right,
					rect.bottom
				)
			);
	}

	handle_ =
		::CreateWindow(
			_wndclass.name().c_str(),
			title.c_str(),
			flags,
			0,
			0,
			decoration_size_.w() + sz.w(),
			decoration_size_.h() + sz.h(),
			0,
			0,
			windows::module_handle(),
			this
		);

	if(
		!handle_
	)
		throw awl::exception(
			FCPPT_TEXT("CreateWindow() failed!")
		);
	
/*
	windows::window_ptr const wnd(
		fcppt::make_shared_ptr<
			windows::window
		>(
			*param.dim(),
			param.title(),
			param.class_name()
		)
	);

	if(rparam)
		windows::choose_and_set_pixel_format(
			windows::gdi_device(
				wnd->hwnd(),
				windows::gdi_device::get_tag()),
			PFD_DRAW_TO_WINDOW |
			PFD_SUPPORT_OPENGL |
			PFD_DOUBLEBUFFER,
			PFD_TYPE_RGBA,
			static_cast<BYTE>(rparam->display_mode().bit_depth()),
			static_cast<BYTE>(rparam->depth_buffer()),
			static_cast<BYTE>(rparam->stencil_buffer()));

	return wnd;
	*/

}

awl::backends::windows::window::~window()
{
	::DestroyWindow(
		handle_
	);

	remove_wndclass_();
}

awl::backends::windows::window::dim_type const
awl::backends::windows::window::size() const
{
	RECT rect;

	if(
		::GetWindowRect(
			handle_,
			&rect
		)
		== FALSE
	)
		throw awl::exception(
			FCPPT_TEXT("GetWindowRect() failed!")
		);

	return
		window::dim(
			rect.right - rect.left - decoration_size_.w(),
			rect.bottom - rect.top - decoration_size_.h()
		);
}

HWND
awl::backends::windows::window::hwnd() const
{
	return handle_;
}

void
awl::backends::windows::window::show()
{
	::ShowWindow(
		hwnd(),
		SW_NORMAL
	);
}
