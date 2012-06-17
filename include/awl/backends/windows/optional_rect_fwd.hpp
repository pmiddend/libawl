#ifndef AWL_BACKENDS_WINDOWS_OPTIONAL_RECT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_OPTIONAL_RECT_FWD_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

typedef fcppt::optional<
	RECT
> optional_rect;

}
}
}

#endif
