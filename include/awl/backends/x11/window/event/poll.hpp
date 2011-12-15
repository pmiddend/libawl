#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_POLL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_POLL_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/instance_fwd.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/optional.hpp>


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
	x11::window::instance &,
	x11::window::event::mask
);

}
}
}
}
}

#endif
