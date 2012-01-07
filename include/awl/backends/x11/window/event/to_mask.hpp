#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_TO_MASK_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/event/optional_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>


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
event::optional_mask const
to_mask(
	x11::window::event::type
);

}
}
}
}
}

#endif
