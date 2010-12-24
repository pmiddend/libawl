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
