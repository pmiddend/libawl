#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_OPTIONAL_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_OPTIONAL_MASK_HPP_INCLUDED

#include <awl/backends/x11/window/event/mask.hpp>
#include <fcppt/optional_impl.hpp>


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

typedef fcppt::optional<
	event::mask
> optional_mask;

}
}
}
}
}

#endif
