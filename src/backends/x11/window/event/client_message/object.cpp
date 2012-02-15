#include <awl/backends/x11/window/event/client_message/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::client_message::object::object(
	XClientMessageEvent const &_event
)
:
	event_(
		_event
	)
{
}

XClientMessageEvent const &
awl::backends::x11::window::event::client_message::object::get() const
{
	return event_;
}
