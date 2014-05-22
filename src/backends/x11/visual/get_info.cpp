#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual/get_info.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::visual::info_unique_ptr
awl::backends::x11::visual::get_info(
	awl::backends::x11::display const &_display,
	long const _mask,
	XVisualInfo const &_info
)
{
	int number_of_items;

	awl::backends::x11::visual::info_unique_ptr ret(
		::XGetVisualInfo(
			_display.get(),
			_mask,
			// libX11 only reads this struct
			&const_cast<
				XVisualInfo &
			>(
				_info
			),
			&number_of_items
		)
	);

	if(
		!ret
	)
		throw awl::exception(
			FCPPT_TEXT("Couldn't get XVisualInfo structure for Visual")
		);

	return
		std::move(
			ret
		);
}
