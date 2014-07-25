#include <awl/backends/x11/default_screen.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/cursor/background_color.hpp>
#include <awl/backends/x11/cursor/create_invisible.hpp>
#include <awl/backends/x11/cursor/create_pixmap.hpp>
#include <awl/backends/x11/cursor/dest_pixmap.hpp>
#include <awl/backends/x11/cursor/foreground_color.hpp>
#include <awl/backends/x11/cursor/holder.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/cursor/object_unique_ptr.hpp>
#include <awl/backends/x11/cursor/source_pixmap.hpp>
#include <awl/backends/x11/pixmap/create_from_data.hpp>
#include <awl/backends/x11/pixmap/dim.hpp>
#include <awl/backends/x11/pixmap/holder.hpp>
#include <awl/backends/x11/pixmap/holder_unique_ptr.hpp>
#include <awl/backends/x11/pixmap/size.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/root.hpp>
#include <awl/cursor/hotspot.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::cursor::object_unique_ptr
awl::backends::x11::cursor::create_invisible(
	awl::backends::x11::display &_display
)
{
	awl::backends::x11::pixmap::size const size{
		8
	};

	std::array<
		char,
		size * size
		/
		8
	> const bm_no_data{{
		0,0,0,0, 0,0,0,0
	}};

	awl::backends::x11::pixmap::holder_unique_ptr const pixmap(
		awl::backends::x11::pixmap::create_from_data(
			// TODO: Is this ok?
			*awl::backends::x11::window::root(
				_display,
				awl::backends::x11::default_screen(
					_display
				)
			),
			awl::backends::x11::pixmap::dim(
				size,
				size
			),
			bm_no_data.data()
		)
	);

	XColor const black{
		0, 0, 0, 0, 0, 0
	};

	return
		fcppt::make_unique_ptr<
			awl::backends::x11::cursor::object
		>(
			awl::backends::x11::cursor::create_pixmap(
				_display,
				awl::backends::x11::cursor::source_pixmap(
					*pixmap
				),
				awl::backends::x11::cursor::dest_pixmap(
					*pixmap
				),
				awl::backends::x11::cursor::foreground_color(
					black
				),
				awl::backends::x11::cursor::background_color(
					black
				),
				awl::cursor::hotspot(
					0,
					0
				)
			)
		);
}
