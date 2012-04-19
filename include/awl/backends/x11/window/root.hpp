#ifndef AWL_BACKENDS_X11_WINDOW_ROOT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ROOT_HPP_INCLUDED

#include <awl/backends/x11/window/object_unique_ptr.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
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
window::object_unique_ptr
root(
	x11::display &,
	x11::screen
);

}
}
}
}

#endif
