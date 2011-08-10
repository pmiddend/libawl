#include <awl/backends/x11/window/create.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/optional_impl.hpp>
#include <X11/Xlib.h>

Window
awl::backends::x11::window::create(
	awl::window::optional_position const &_position,
	awl::window::optional_dim const &_dim,
	x11::display &_display,
	x11::screen const _screen,
	x11::colormap const &_colormap,
	x11::visual const &_visual
)
{
	XSetWindowAttributes swa;

	swa.colormap = _colormap.get();

	swa.border_pixel = 0;

	swa.event_mask = StructureNotifyMask | FocusChangeMask;

	// always returns a handle
	return
		::XCreateWindow(
			_display.get(),
			::XRootWindow(
				_display.get(),
				_screen.get()
			),
			_position
			?
				static_cast<
					int
				>(
					_position->x()
				)
			:
				0,
			_position
			?
				static_cast<
					int
				>(
					_position->y()
				)
			:
				0,
			static_cast<
				unsigned
			>(
				_dim->w()
			),
			static_cast<
				unsigned
			>(
				_dim->h()
			),
			// border_width
			0,
			_visual.info().depth,
			InputOutput,
			&_visual.get(),
			CWColormap | CWBorderPixel | CWEventMask,
			&swa
		);
}
