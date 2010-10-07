#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::colormap::colormap(
	display_ptr const _display,
	int const screen,
	visual_ptr const visual)
:
	display_(
		_display),
	c_(
		XCreateColormap(
			display_->get(),
			XRootWindow(
				display_->get(),
				screen),
			visual->get(),
			AllocNone))
{
	if(get() == 0)
		throw exception(
			FCPPT_TEXT("XCreateColormap() failed!"));
}

awl::backends::x11::colormap::~colormap()
{
	XFreeColormap(
		display_->get(),
		get());
}

Colormap &
awl::backends::x11::colormap::get()
{
	return c_;
}
