#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_RETURN_TYPE_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_RETURN_TYPE_FWD_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

typedef fcppt::optional<
	LRESULT
> return_type;

}
}
}
}
}

#endif
