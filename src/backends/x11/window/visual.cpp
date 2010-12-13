#include <awl/backends/x11/window/visual.hpp>
#include <awl/backends/x11/window/attributes.hpp>
#include <awl/backends/x11/visual.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <X11/Xlib.h>

awl::backends::x11::visual_ptr const
awl::backends::x11::window::visual(
	Display *const _display,
	Window const _window
)
{
	return
		fcppt::make_shared_ptr<
			x11::visual
		>(
			_display,
			window::attributes(
				_display,
				_window
			).visual
		);
}
