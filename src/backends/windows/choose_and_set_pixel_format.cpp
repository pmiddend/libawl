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


#include <awl/backends/windows/choose_and_set_pixel_format.hpp>
#include <awl/backends/windows/gdi_device.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

void
awl::backends::windows::choose_and_set_pixel_format(
	windows::gdi_device const &_dc,
	DWORD const _flags,
	BYTE const _pixel_type,
	BYTE const _depth,
	BYTE const _depth_buffer,
	BYTE const _stencil_buffer
)
{
	PIXELFORMATDESCRIPTOR const pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),  // Size Of This Pixel Format Descriptor
			1,                      // Version Number
			_flags,
			_pixel_type,            // Request An RGBA Format
			_depth,                 // Select Our Color Depth
			0, 0, 0, 0, 0, 0,       // Color Bits Ignored
			0,                      // No Alpha Buffer
			0,                      // Shift Bit Ignored
			0,                      // No Accumulation Buffer
			0, 0, 0, 0,             // Accumulation Bits Ignored
			_depth_buffer,
			_stencil_buffer,
			0,                      // No Auxiliary Buffer
			PFD_MAIN_PLANE,         // Main Drawing Layer
			0,                      // Reserved
			0, 0, 0                 // Layer Masks Ignored
	};

	int const format(
		::ChoosePixelFormat(
			_dc.hdc(),
			&pfd
		)
	);

	if(
		format == 0
	)
		throw awl::exception(
			FCPPT_TEXT("ChoosePixelFormat() failed")
		);

	if(
		::SetPixelFormat(
			_dc.hdc(),
			format,
			&pfd
		)
		== FALSE
	)
		throw awl::exception(
			FCPPT_TEXT("SetPixelFormat() failed")
		);
}
