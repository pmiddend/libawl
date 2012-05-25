#include <awl/exception.hpp>
#include <awl/backends/linux/fd/epoll/fd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


awl::backends::linux::fd::epoll::fd::fd()
:
	fd_(
		::epoll_create(
			1 // some hint for the number of fds
		)
	)
{
	if(
		fd_.get() == -1
	)
		throw awl::exception(
			FCPPT_TEXT("epoll_create failed!")
		);
}

awl::backends::linux::fd::epoll::fd::~fd()
{
	::close(
		fd_.get()
	);
}

awl::backends::linux::fd::object const
awl::backends::linux::fd::epoll::fd::get() const
{
	return fd_;
}
