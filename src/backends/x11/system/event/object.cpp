#include <awl/backends/x11/system/event/object.hpp>

awl::backends::x11::system::event::object::object(
	XGenericEventCookie const &_event
)
:
	event_(_event)
{
}

XGenericEventCookie const &
awl::backends::x11::system::event::object::get() const
{
	return event_;
}

XGenericEventCookie &
awl::backends::x11::system::event::object::get()
{
	return event_;
}
