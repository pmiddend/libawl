#ifndef AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/window/instance_fwd.hpp>
#include <awl/backends/x11/visual_unique_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_SYMBOL
x11::visual_unique_ptr
visual(
	x11::window::instance &
);

}
}
}
}

#endif
