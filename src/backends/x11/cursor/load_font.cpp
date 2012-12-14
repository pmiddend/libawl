#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/cursor/holder.hpp>
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/load_font.hpp>
#include <awl/backends/x11/cursor/shape.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::cursor::holder_unique_ptr
awl::backends::x11::cursor::load_font(
	awl::backends::x11::display const &_display,
	awl::backends::x11::cursor::shape const _shape
)
{
	return
		fcppt::make_unique_ptr<
			awl::backends::x11::cursor::holder
		>(
			_display,
			::XCreateFontCursor(
				_display.get(),
				_shape.get()
			)
		);
}
