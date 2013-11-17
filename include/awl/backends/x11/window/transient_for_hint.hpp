#ifndef AWL_BACKENDS_X11_WINDOW_TRANSIENT_FOR_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_TRANSIENT_FOR_HINT_HPP_INCLUDED

#include <awl/symbol.hpp>
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
void
transient_for_hint(
	window::object &,
	window::object &prop_window
);

}
}
}
}

#endif
