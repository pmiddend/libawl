#ifndef AWL_BACKENDS_WINDOWS_CURSOR_XOR_PLANE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_XOR_PLANE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

FCPPT_MAKE_STRONG_TYPEDEF(
	VOID const *,
	xor_plane
);

}
}
}
}

#endif
