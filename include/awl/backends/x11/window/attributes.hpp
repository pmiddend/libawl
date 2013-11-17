#ifndef AWL_BACKENDS_X11_WINDOW_ATTRIBUTES_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ATTRIBUTES_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
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
XWindowAttributes const
attributes(
	x11::window::object &
);

}
}
}
}

#endif
