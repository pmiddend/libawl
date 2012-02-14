#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/holder.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::holder::holder(
	x11::display &_display,
	Window const _window
)
:
	display_(
		_display
	),
	window_(
		_window
	)
{
}

awl::backends::x11::window::holder::~holder()
{
	this->do_destroy();
}

void
awl::backends::x11::window::holder::destroy()
{
	this->do_destroy();

	window_ = None;
}

Window
awl::backends::x11::window::holder::get() const
{
	return window_;
}

void
awl::backends::x11::window::holder::do_destroy()
{
	if(
		window_
		!=
		None
	)
		::XDestroyWindow(
			display_.get(),
			window_
		);
}
