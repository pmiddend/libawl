#ifndef AWL_BACKENDS_X11_EVENT_PENDING_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_PENDING_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{

AWL_SYMBOL
bool
pending(
	awl::backends::x11::display const &
);

}
}
}
}

#endif
