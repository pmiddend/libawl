#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/root.hpp>
#include <awl/backends/x11/window/wrapped_object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::object_unique_ptr
awl::backends::x11::window::root(
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen
)
{
	return
		awl::backends::x11::window::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::x11::window::wrapped_object
			>(
				_display,
				_screen,
				::XRootWindow(
					_display.get(),
					_screen.get()
				)
			)
		);
}
