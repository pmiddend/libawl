#ifndef AWL_BACKENDS_WINDOWS_OPTIONAL_POINT_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_OPTIONAL_POINT_FWD_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

typedef fcppt::optional<
	POINT
> optional_point;

}
}
}

#endif
