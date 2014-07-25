#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/cursor/background_color.hpp>
#include <awl/backends/x11/cursor/create_pixmap.hpp>
#include <awl/backends/x11/cursor/foreground_color.hpp>
#include <awl/backends/x11/cursor/dest_pixmap.hpp>
#include <awl/backends/x11/cursor/holder.hpp>
#include <awl/backends/x11/cursor/holder_unique_ptr.hpp>
#include <awl/backends/x11/cursor/source_pixmap.hpp>
#include <awl/backends/x11/pixmap/holder.hpp>
#include <awl/cursor/hotspot.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::cursor::holder_unique_ptr
awl::backends::x11::cursor::create_pixmap(
	awl::backends::x11::display const &_display,
	awl::backends::x11::cursor::source_pixmap const &_source_pixmap,
	awl::backends::x11::cursor::dest_pixmap const &_dest_pixmap,
	awl::backends::x11::cursor::foreground_color const &_foreground_color,
	awl::backends::x11::cursor::background_color const &_background_color,
	awl::cursor::hotspot const _hotspot
)
{
	Cursor const result{
		::XCreatePixmapCursor(
			_display.get(),
			_source_pixmap.get().get(),
			_dest_pixmap.get().get(),
			const_cast<
				XColor *
			>(
				&_foreground_color.get()
			),
			const_cast<
				XColor *
			>(
				&_background_color.get()
			),
			_hotspot.x(),
			_hotspot.y()
		)
	};

	if(
		result
		==
		None
	)
		throw
			awl::exception{
				FCPPT_TEXT("XCreatePixmapCursor failed!")
			};

	return
		fcppt::make_unique_ptr<
			awl::backends::x11::cursor::holder
		>(
			_display,
			result
		);
}
