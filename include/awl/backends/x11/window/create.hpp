#ifndef AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED

#include <awl/backends/x11/colormap_fwd.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual_fwd.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/optional_position.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

Window
create(
	awl::window::optional_position const &,
	awl::window::optional_dim const &,
	x11::display &,
	x11::screen,
	x11::colormap const &,
	x11::visual const &
);

}
}
}
}

#endif
