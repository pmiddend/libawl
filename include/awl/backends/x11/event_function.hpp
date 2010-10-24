#ifndef AWL_BACKENDS_X11_EVENT_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FUNCTION_HPP_INCLUDED

#include <awl/backends/x11/event_fwd.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

typedef
void
event_function(
	x11::event const &
);

}
}
}

#endif
