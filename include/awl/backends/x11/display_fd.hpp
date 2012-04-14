#ifndef AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_FD_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/event/fd/object.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

AWL_SYMBOL
awl::backends::x11::event::fd::object const
display_fd(
	awl::backends::x11::display &
);

}
}
}

#endif
