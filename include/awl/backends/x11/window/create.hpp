#ifndef AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CREATE_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/colormap_fwd.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/cursor/const_optional_object_ref_fwd.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/window/optional_dim_fwd.hpp>
#include <awl/window/optional_pos_fwd.hpp>
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
	awl::window::optional_pos const &,
	awl::window::optional_dim const &,
	awl::backends::x11::display &,
	awl::backends::x11::screen,
	awl::backends::x11::colormap const &,
	awl::backends::x11::visual::object const &,
	awl::backends::x11::cursor::const_optional_object_ref const &
);

}
}
}
}

#endif
