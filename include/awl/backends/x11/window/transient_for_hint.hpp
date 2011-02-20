#ifndef AWL_BACKENDS_X11_WINDOW_TRANSIENT_FOR_HINT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_TRANSIENT_FOR_HINT_HPP_INCLUDED

#include <awl/backends/x11/window/instance_fwd.hpp>
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
void
transient_for_hint(
	window::instance &,
	window::instance &prop_window
);

}
}
}
}

#endif
