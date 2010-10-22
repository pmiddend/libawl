#ifndef AWL_BACKENDS_X11_EVENT_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FUNCTION_HPP_INCLUDED

#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{

typedef
void
event_function(
	XEvent const &
);

}
}
}

#endif
