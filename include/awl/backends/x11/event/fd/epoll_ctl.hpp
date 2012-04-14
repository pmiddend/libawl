#ifndef AWL_BACKENDS_X11_EVENT_FD_EPOLL_CTL_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_EPOLL_CTL_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/event/fd/epoll_fd_fwd.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


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
void
epoll_ctl(
	awl::backends::x11::event::fd::epoll_fd const &,
	awl::backends::x11::event::fd::object const &,
	epoll_event *
);

}
}
}
}
}

#endif
