#include <awl/backends/x11/window/holder.hpp>
#include <awl/backends/x11/display.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::window::holder::holder(
	x11::display &_display,
	Window const _window
)
:
	display_(_display),
	window_(_window)
{
}

awl::backends::x11::window::holder::~holder()
{
	::XDestroyWindow(
		display_.get(),
		window_
	);
}

Window
awl::backends::x11::window::holder::get() const
{
	return window_;
}
