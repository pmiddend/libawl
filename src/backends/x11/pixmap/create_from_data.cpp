#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/pixmap/create_from_data.hpp>
#include <awl/backends/x11/pixmap/dim.hpp>
#include <awl/backends/x11/pixmap/holder.hpp>
#include <awl/backends/x11/pixmap/holder_unique_ptr.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::pixmap::holder_unique_ptr
awl::backends::x11::pixmap::create_from_data(
	awl::backends::x11::window::object const &_window,
	awl::backends::x11::pixmap::dim const _dim,
	char const *const _data
)
{
	Pixmap const result{
		::XCreateBitmapFromData(
			_window.display().get(),
			_window.get(),
			_data,
			_dim.w(),
			_dim.h()
		)
	};

	if(
		result
		==
		None
	)
		throw
			awl::exception{
				FCPPT_TEXT("XCreateBitmapFromData failed!")
			};

	return
		fcppt::make_unique_ptr<
			awl::backends::x11::pixmap::holder
		>(
			_window.display(),
			result
		);
}
