#include <awl/backends/x11/window/root.hpp>
#include <awl/backends/x11/window/wrapped_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window::instance_unique_ptr
awl::backends::x11::window::root(
	x11::display &_display,
	x11::screen const _screen
)
{
	return
		awl::backends::x11::window::instance_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::x11::window::wrapped_instance
			>(
				fcppt::ref(
					_display
				),
				_screen,
				::XRootWindow(
					_display.get(),
					_screen.get()
				)
			)
		);
}
