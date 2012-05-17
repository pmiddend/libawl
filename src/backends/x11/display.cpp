#include <awl/exception.hpp>
#include <awl/backends/x11/discard.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/to_x11_bool.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::display::display()
{
}

awl::backends::x11::display::~display()
{
}

void
awl::backends::x11::display::sync(
	awl::backends::x11::discard const _discard
)
{
	// always returns 1

	::XSync(
		this->get(),
		awl::backends::x11::to_x11_bool(
			_discard.get()
		)
	);
}
