#ifndef AWL_BACKENDS_X11_WINDOW_CHANGE_WM_PROTOCOLS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CHANGE_WM_PROTOCOLS_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/atoms_fwd.hpp>
#include <awl/backends/x11/window/instance_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_SYMBOL
void
set_wm_protocols(
	awl::backends::x11::window::instance const &,
	awl::backends::x11::window::atoms const &
);

}
}
}
}

#endif
