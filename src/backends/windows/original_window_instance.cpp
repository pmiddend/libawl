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


#include <awl/backends/windows/original_window_instance.hpp>
#include <awl/backends/windows/choose_and_set_pixel_format.hpp>
#include <awl/backends/windows/wndclass.hpp>
#include <awl/backends/windows/module_handle.hpp>
#include <awl/backends/windows/gdi_device.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/window/parameters.hpp>
#include <awl/exception.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/text.hpp>

awl::backends::windows::original_window_instance::original_window_instance(
	awl::window::parameters const &_param,
	windows::wndclass &_wndclass,
	windows::wndclass_remove_callback const &_remove_wndclass
)
:
	decoration_size_(
		decoration_rect::null()
	),
	handle_(
		0
	),
	remove_wndclass_(
		_remove_wndclass
	)
{

	DWORD const flags(
		WS_OVERLAPPEDWINDOW
	);

	{
		RECT rect;

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
		CreateWindow(
			_wndclass.name().c_str(),
			_param.title().c_str(),
			flags,
			0,
			0,
			_param.size()
			?
				decoration_size_.w()
				+ _param.size()->w()
			:
				CW_USEDEFAULT,
			_param.size()
			?
				decoration_size_.h()
				+ _param.size()->h()
			:
				CW_USEDEFAULT,
			0,
			0,
			windows::module_handle(),
			0
		);

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

awl::backends::windows::original_window_instance::~original_window_instance()
{
	::DestroyWindow(
		handle_
	);

	remove_wndclass_();
}

awl::window::dim const
awl::backends::windows::original_window_instance::size() const
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
		awl::window::dim(
			rect.right - rect.left - decoration_size_.w(),
			rect.bottom - rect.top - decoration_size_.h()
		);
}

HWND
awl::backends::windows::original_window_instance::hwnd() const
{
	return handle_;
}

void
awl::backends::windows::original_window_instance::show()
{
	::ShowWindow(
		hwnd(),
		SW_NORMAL
	);
}
