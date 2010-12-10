#include <awl/backends/x11/event.hpp>

awl::backends::x11::event::event(
	XEvent const &_event
)
:
	event_(_event)
{}

XEvent const &
awl::backends::x11::event::get() const
{
	return event_;
}

XEvent &
awl::backends::x11::event::get()
{
	return event_;
}
