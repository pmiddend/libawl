#ifndef AWL_BACKENDS_X11_EVENT_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_HPP_INCLUDED

#include <awl/backends/x11/event_fwd.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{

class event
{
public:
	explicit event(
		XEvent const &
	);

	XEvent const &
	get() const;

	XEvent &
	get();
private:
	XEvent event_;
};

}
}
}

#endif
