#ifndef AWL_BACKENDS_X11_EVENT_FD_EPOLL_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_EPOLL_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/event/fd/duration.hpp>
#include <awl/backends/x11/event/fd/set_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{
namespace fd
{

AWL_SYMBOL
unsigned
epoll(
	awl::backends::x11::event::fd::set &,
	awl::backends::x11::event::fd::duration const &
);

}
}
}
}
}

#endif
