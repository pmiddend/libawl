#ifndef AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_VISUAL_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

AWL_SYMBOL
awl::backends::x11::visual::object_unique_ptr
visual(
	awl::backends::x11::window::object &
);

}
}
}
}

#endif
