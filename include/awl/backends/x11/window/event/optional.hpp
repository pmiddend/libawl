#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_OPTIONAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_OPTIONAL_HPP_INCLUDED

#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <fcppt/optional_fwd.hpp>

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
	x11::window::event::object
> optional;

}
}
}
}
}

#endif
