#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <X11/Xlib.h>

bool
awl::backends::x11::window::event::filter(
	event::object _event,
	x11::window::instance &_window
)
{
	return
		::XFilterEvent(
			&_event.get(),
			_window.get()
		)
		== True;

}
