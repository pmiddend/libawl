#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CHANGE_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CHANGE_MASK_HPP_INCLUDED

#include <awl/backends/x11/window/instance_fwd.hpp>
#include <awl/backends/x11/window/event/mask.hpp>


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

void
change_mask(
	x11::window::instance &,
	x11::window::event::mask
);

}
}
}
}
}

#endif
