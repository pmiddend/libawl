#ifndef AWL_BACKENDS_X11_CHANGE_EVENT_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_CHANGE_EVENT_MASK_HPP_INCLUDED

#include <awl/backends/x11/window_instance_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

void
change_event_mask(
	x11::window_instance_ptr,
	long mask
);

}
}
}

#endif
