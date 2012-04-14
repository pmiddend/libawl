#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/event/pending.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


bool
awl::backends::x11::event::pending(
	awl::backends::x11::display const &_display
)
{
	return
		::XPending(
			_display.get()
		)
		> 0
		;
}
