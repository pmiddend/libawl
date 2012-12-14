#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/get_input_focus.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/window/object_unique_ptr.hpp>
#include <awl/backends/x11/window/wrapped_object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::object_unique_ptr
awl::backends::x11::get_input_focus(
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen
)
{
	Window window_return;

	int revert_to_return;

	// Always returns 1
	::XGetInputFocus(
		_display.get(),
		&window_return,
		&revert_to_return
	);

	return
		window_return
		!= None
		&&
		window_return
		!= PointerRoot
		?
			awl::backends::x11::window::object_unique_ptr(
				fcppt::make_unique_ptr<
					awl::backends::x11::window::wrapped_object
				>(
					_display,
					_screen,
					window_return
				)
			)
		:
			awl::backends::x11::window::object_unique_ptr()
		;
}
