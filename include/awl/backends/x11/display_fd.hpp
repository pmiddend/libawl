#ifndef AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

AWL_SYMBOL
int
display_fd(
	awl::backends::x11::display &
);

}
}
}

#endif
