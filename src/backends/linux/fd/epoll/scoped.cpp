#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/epoll/scoped.hpp>
#include <awl/backends/linux/fd/epoll/set.hpp>


awl::backends::linux::fd::epoll::scoped::scoped(
	awl::backends::linux::fd::epoll::set &_set,
	awl::backends::linux::fd::object const _fd
)
:
	set_(
		_set
	),
	fd_(
		_fd
	)
{
	set_.add(
		fd_
	);
}

awl::backends::linux::fd::epoll::scoped::~scoped()
{
	set_.remove(
		fd_
	);
}
