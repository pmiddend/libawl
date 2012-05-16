#ifndef AWL_BACKENDS_X11_EVENT_FD_OPTIONAL_DURATION_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_OPTIONAL_DURATION_FWD_HPP_INCLUDED

#include <awl/backends/x11/event/fd/duration.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{
namespace fd
{

typedef fcppt::optional<
	awl::backends::x11::event::fd::duration
> optional_duration;

}
}
}
}
}

#endif
