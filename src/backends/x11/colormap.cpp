#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::colormap::colormap(
	x11::display_ptr const _display,
	x11::screen const _screen,
	x11::visual_ptr const _visual
)
:
	display_(
		_display
	),
	colormap_(
		::XCreateColormap(
			display_->get(),
			::XRootWindow(
				display_->get(),
				_screen.get()
			),
			_visual->get(),
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
		display_->get(),
		get()
	);
}

Colormap &
awl::backends::x11::colormap::get()
{
	return colormap_;
}
