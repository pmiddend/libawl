#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/transient_for_hint.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::window::transient_for_hint(
	window::instance &_window,
	window::instance &_prop_window
)
{
	// always returns 1
	::XSetTransientForHint(
		_window.display().get(),
		_window.get(),
		_prop_window.get()
	);
}
