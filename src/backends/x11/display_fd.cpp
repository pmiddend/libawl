#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xlibint.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::event::fd::object const
awl::backends::x11::display_fd(
	awl::backends::x11::display &_display
)
{
	return
		awl::backends::x11::event::fd::object(
			_display.get()->fd
		);
}
