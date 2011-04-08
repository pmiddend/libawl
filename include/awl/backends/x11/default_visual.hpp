#ifndef AWL_BACKENDS_X11_DEFAULT_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_DEFAULT_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/visual_unique_ptr.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

AWL_SYMBOL
x11::visual_unique_ptr
default_visual(
	x11::display &,
	x11::screen
);

}
}
}

#endif
