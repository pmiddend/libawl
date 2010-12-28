#include <awl/backends/x11/to_x11_bool.hpp>
#include <awl/backends/x11/original_display.hpp>
#include <awl/exception.hpp>
#include <X11/Xlib.h>
#include <fcppt/text.hpp>

awl::backends::x11::original_display::original_display()
:
	ptr_(
		::XOpenDisplay(
			0
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
