#include <awl/backends/x11/window/holder.hpp>
#include <awl/backends/x11/display.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window::holder::holder(
	x11::display_ptr const _display,
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
		display_->get(),
		window_
	);
}

Window
awl::backends::x11::window::holder::get() const
{
	return window_;
}