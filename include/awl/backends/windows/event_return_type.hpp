#ifndef AWL_BACKENDS_WINDOWS_EVENT_RETURN_TYPE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_RETURN_TYPE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <fcppt/optional_fwd.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

typedef fcppt::optional<
	LRESULT
> event_return_type;

}
}
}

#endif
