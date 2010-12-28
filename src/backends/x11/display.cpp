#include <awl/backends/x11/to_x11_bool.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/exception.hpp>
#include <X11/Xlib.h>
#include <fcppt/text.hpp>

awl::backends::x11::display::display()
{
}

awl::backends::x11::display::~display()
{
}

void
awl::backends::x11::display::sync(
	bool const _discard
)
{
	// always returns 1

	::XSync(
		get(),
		x11::to_x11_bool(
			_discard
		)
	);
}
