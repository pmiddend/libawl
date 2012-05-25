#ifndef AWL_BACKENDS_LINUX_FD_EPOLL_CTL_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_EPOLL_CTL_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/epoll/fd_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
{
namespace epoll
{

AWL_SYMBOL
void
ctl(
	awl::backends::linux::fd::epoll::fd const &,
	awl::backends::linux::fd::object const &,
	epoll_event *
);

}
}
}
}
}

#endif
