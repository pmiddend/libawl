#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/display.hpp>
#include <X11/Xlib.h>
#include <X11/Xlibint.h>

int
awl::backends::x11::display_fd(
	x11::display_ptr const _display
)
{
	return
		_display->get()->fd;
}
