#include <awl/exception.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::colormap::colormap(
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen,
	awl::backends::x11::visual::object const &_visual
)
:
	display_(
		_display
	),
	colormap_(
		::XCreateColormap(
			display_.get(),
			::XRootWindow(
				display_.get(),
				_screen.get()
			),
			&_visual.get(),
			AllocNone
		)
	)
{
	if(
		colormap_ == 0
	)
		throw awl::exception(
			FCPPT_TEXT("XCreateColormap() failed!")
		);
}

awl::backends::x11::colormap::~colormap()
{
	::XFreeColormap(
		display_.get(),
		this->get()
	);
}

Colormap &
awl::backends::x11::colormap::get()
{
	return colormap_;
}

Colormap const &
awl::backends::x11::colormap::get() const
{
	return colormap_;
}
