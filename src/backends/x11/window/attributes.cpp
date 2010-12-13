#include <awl/backends/x11/window/attributes.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

XWindowAttributes const
awl::backends::x11::window::attributes(
	Display *const _display,
	Window const _window
)
{
	XWindowAttributes ret;

	if(
		::XGetWindowAttributes(
			_display,
			_window,
			&ret
		)
		!= 1
	)
		throw awl::exception(
			FCPPT_TEXT("XGetWindowAttributes() failed!")
		);
	
	return ret;
}
