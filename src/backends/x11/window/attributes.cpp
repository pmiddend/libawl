#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/attributes.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


XWindowAttributes const
awl::backends::x11::window::attributes(
	x11::window::object &_window
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
