#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CHANGE_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CHANGE_MASK_HPP_INCLUDED

#include <awl/backends/x11/window/instance_ptr.hpp>

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
	x11::window::instance_ptr,
	long mask
);

}
}
}
}
}

#endif
