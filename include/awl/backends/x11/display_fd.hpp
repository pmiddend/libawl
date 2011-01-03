#ifndef AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED

#include <awl/backends/x11/display_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

AWL_SYMBOL
int
display_fd(
	x11::display_ptr
);

}
}
}

#endif
