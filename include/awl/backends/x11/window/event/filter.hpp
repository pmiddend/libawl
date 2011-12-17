#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_FILTER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_FILTER_HPP_INCLUDED

#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/backends/x11/window/instance_fwd.hpp>
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
bool
filter(
	event::object,
	x11::window::instance const &
);

}
}
}
}
}

#endif
