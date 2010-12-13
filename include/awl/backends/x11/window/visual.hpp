#ifndef AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/visual_ptr.hpp>
#include <awl/symbol.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_SYMBOL
x11::visual_ptr const
visual(
	Display *,
	Window
);

}
}
}
}

#endif
