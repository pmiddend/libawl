#include <awl/backends/x11/window/attributes.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>
#include <X11/Xlib.h>

XWindowAttributes const
awl::backends::x11::window::attributes(
	x11::window::instance &_window
)
{
	XWindowAttributes ret;

	if(
		::XGetWindowAttributes(
			_window.display().get(),
			_window.get(),
			&ret
		)
		!= 1
	)
		throw awl::exception(
			FCPPT_TEXT("XGetWindowAttributes() failed!")
		);

	return ret;
}
