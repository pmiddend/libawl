#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/cursor/holder.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::cursor::holder::holder(
	awl::backends::x11::display const &_display,
	Cursor const _cursor
)
:
	display_(
		_display
	),
	cursor_(
		_cursor
	)
{
}

awl::backends::x11::cursor::holder::~holder()
{
	::XFreeCursor(
		display_.get(),
		cursor_
	);
}

Cursor
awl::backends::x11::cursor::holder::get() const
{
	return cursor_;
}
