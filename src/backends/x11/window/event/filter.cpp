#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


bool
awl::backends::x11::window::event::filter(
	event::object _event,
	x11::window::object const &_window
)
{
	return
		::XFilterEvent(
			&_event.get(),
			_window.get()
		)
		== True;

}
