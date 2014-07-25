#ifndef AWL_BACKENDS_X11_WINDOW_ROOT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ROOT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/window/object_unique_ptr.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_SYMBOL
awl::backends::x11::window::object_unique_ptr
root(
	awl::backends::x11::display &,
	awl::backends::x11::screen
);

}
}
}
}

#endif
