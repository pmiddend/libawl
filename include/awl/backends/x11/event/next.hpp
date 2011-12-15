#ifndef AWL_BACKENDS_X11_EVENT_NEXT_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_NEXT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/event/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{

AWL_SYMBOL
x11::event::object const
next(
	x11::display &
);

}
}
}
}

#endif
