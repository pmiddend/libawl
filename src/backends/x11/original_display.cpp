#include <awl/exception.hpp>
#include <awl/backends/x11/original_display.hpp>
#include <awl/backends/x11/to_x11_bool.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::original_display::original_display()
:
	ptr_(
		::XOpenDisplay(
			nullptr
		)
	)
{
	if(
		!ptr_
	)
		throw awl::exception(
			FCPPT_TEXT("XOpenDisplay failed or dsp is 0!")
		);
}

Display *
awl::backends::x11::original_display::get() const
{
	return ptr_;
}

awl::backends::x11::original_display::~original_display()
{
	::XCloseDisplay(
		ptr_
	);
}
