#ifndef AWL_BACKENDS_X11_EVENT_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_HPP_INCLUDED

#include <awl/backends/x11/event_fwd.hpp>
#include <awl/symbol.hpp>
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
	AWL_SYMBOL
	explicit event(
		XEvent const &
	);

	AWL_SYMBOL
	XEvent const &
	get() const;

	AWL_SYMBOL
	XEvent &
	get();
private:
	XEvent event_;
};

}
}
}

#endif
