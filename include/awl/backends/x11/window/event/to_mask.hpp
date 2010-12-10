#ifndef AWL_BACKENDS_X11_TO_EVENT_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_TO_EVENT_MASK_HPP_INCLUDED

namespace awl
{
namespace backends
{
namespace x11
{

long
to_event_mask(
	int event_type
);

}
}
}

#endif
