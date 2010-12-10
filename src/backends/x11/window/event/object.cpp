#include <awl/backends/x11/window/event/object.hpp>

awl::backends::x11::window::event::object::object(
	XEvent const &_event
)
:
	event_(_event)
{}

XEvent const &
awl::backends::x11::window::event::object::get() const
{
	return event_;
}

XEvent &
awl::backends::x11::window::event::object::get()
{
	return event_;
}
