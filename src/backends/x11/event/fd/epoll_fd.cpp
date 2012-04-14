#include <awl/exception.hpp>
#include <awl/backends/x11/event/fd/epoll_fd.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::event::fd::epoll_fd::epoll_fd()
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

awl::backends::x11::event::fd::epoll_fd::~epoll_fd()
{
	::close(
		fd_.get()
	);
}

awl::backends::x11::event::fd::object const
awl::backends::x11::event::fd::epoll_fd::get() const
{
	return fd_;
}
