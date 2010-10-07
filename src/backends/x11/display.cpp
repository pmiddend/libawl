#include <awl/backends/x11/display.hpp>
#include <awl/exception.hpp>
#include <X11/Xlib.h>
#include <fcppt/text.hpp>

awl::backends::x11::display::display()
:
	ptr_(
		XOpenDisplay(
			0))
{
	if(!ptr_)
		throw exception(
			FCPPT_TEXT("XOpenDisplay failed or dsp is 0!"));
}

Display *
awl::backends::x11::display::get() const
{
	return ptr_;
}

awl::backends::x11::display::~display()
{
	XCloseDisplay(
		ptr_);
}
