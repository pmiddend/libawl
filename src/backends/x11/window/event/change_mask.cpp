#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::window::event::change_mask(
	x11::window::instance &_window,
	x11::window::event::mask const _mask
)
{
	XSetWindowAttributes swa;

	swa.event_mask = _mask.get();

	// always returns 1
	::XChangeWindowAttributes(
		_window.display().get(),
		_window.get(),
		CWEventMask,
		&swa
	);
}
