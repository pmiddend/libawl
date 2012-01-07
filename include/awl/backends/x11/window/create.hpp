#ifndef AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/colormap_fwd.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual_fwd.hpp>
#include <awl/window/optional_dim.hpp>
#include <awl/window/optional_position.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_SYMBOL
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
