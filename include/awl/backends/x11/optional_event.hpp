#ifndef AWL_BACKENDS_X11_OPTIONAL_EVENT_HPP_INCLUDED
#define AWL_BACKENDS_X11_OPTIONAL_EVENT_HPP_INCLUDED

#include <awl/backends/x11/event_fwd.hpp>
#include <fcppt/optional_fwd.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

typedef fcppt::optional<
	x11::event
> optional_event;

}
}
}

#endif
