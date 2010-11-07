#include <awl/backends/x11/change_event_mask.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <X11/Xlib.h>

void
awl::backends::x11::change_event_mask(
	x11::window_instance_ptr const _window,
	long const _mask
)
{
	XSetWindowAttributes swa;
                
	swa.event_mask = _mask;

	// always returns 1
	::XChangeWindowAttributes(
		_window->display()->get(),
		_window->get(),
		CWEventMask,
		&swa
	);
}
