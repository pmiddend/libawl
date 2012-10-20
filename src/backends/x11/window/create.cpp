#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/cursor/const_optional_object_ref.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/create.hpp>
#include <awl/window/optional_position.hpp>
#include <awl/window/optional_dim.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


Window
awl::backends::x11::window::create(
	awl::window::optional_position const &_position,
	awl::window::optional_dim const &_dim,
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen,
	awl::backends::x11::colormap const &_colormap,
	awl::backends::x11::visual::object const &_visual,
	awl::backends::x11::cursor::const_optional_object_ref const &_cursor
)
{
	unsigned long value_mask(
		CWColormap
		|
		CWBorderPixel
		|
		CWEventMask
	);

	XSetWindowAttributes swa;

	swa.colormap = _colormap.get();

	swa.border_pixel = 0;

	swa.event_mask = StructureNotifyMask | FocusChangeMask;

	if(
		_cursor
	)
	{
		swa.cursor = _cursor->get();

		value_mask |= CWCursor;
	}

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
			value_mask,
			&swa
		);
}
