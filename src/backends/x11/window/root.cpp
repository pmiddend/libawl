#include <awl/backends/x11/window/root.hpp>
#include <awl/backends/x11/window/wrapped_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window::instance_ptr const
awl::backends::x11::window::root(
	x11::display_ptr const _display,
	x11::screen const _screen
)
{
	return
		fcppt::make_shared_ptr<
			awl::backends::x11::window::wrapped_instance
		>(
			_display,
			_screen,
			::XRootWindow(
				_display->get(),
				_screen.get()
			)
		);
}
