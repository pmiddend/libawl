#ifndef AWL_BACKENDS_WINDOWS_CHOOSE_AND_SET_PIXEL_FORMAT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CHOOSE_AND_SET_PIXEL_FORMAT_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/gdi_device_fwd.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

AWL_SYMBOL
void
choose_and_set_pixel_format(
	windows::gdi_device const &,
	DWORD flags,
	BYTE pixel_type,
	BYTE depth,
	BYTE depth_buffer,
	BYTE stencil_buffer
);

}
}
}

#endif
