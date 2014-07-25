#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/pixmap/holder.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::pixmap::holder::holder(
	awl::backends::x11::display const &_display,
	Pixmap const _pixmap
)
:
	display_(
		_display
	),
	pixmap_(
		_pixmap
	)
{
}

awl::backends::x11::pixmap::holder::~holder()
{
	::XFreePixmap(
		display_.get(),
		pixmap_
	);
}

Pixmap
awl::backends::x11::pixmap::holder::get() const
{
	return
		pixmap_;
}
