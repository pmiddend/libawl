#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xlibint.h>
#include <fcppt/config/external_end.hpp>


int
awl::backends::x11::display_fd(
	awl::backends::x11::display &_display
)
{
	return
		_display.get()->fd;
}
