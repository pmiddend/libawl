#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_POLL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_POLL_HPP_INCLUDED

#include <awl/backends/x11/window/event/optional.hpp>
#include <awl/backends/x11/window/instance_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

AWL_SYMBOL
x11::window::event::optional const
poll(
	x11::window::instance_ptr,
	long event_mask
);

}
}
}
}
}

#endif
