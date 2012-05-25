#include <fcppt/null_ptr.hpp>
#include <fcppt/text.hpp>
#include <awl/exception.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/epoll/ctl.hpp>
#include <awl/backends/linux/fd/epoll/fd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::linux::fd::epoll::ctl(
	awl::backends::linux::fd::epoll::fd const &_epoll_fd,
	awl::backends::linux::fd::object const &_fd,
	epoll_event *const _data
)
{

	if(
		_data != fcppt::null_ptr()
	)
	{
		_data->events = EPOLLIN;

		_data->data.fd = _fd.get();
	}

	if(
		::epoll_ctl(
			_epoll_fd.get().get(),
			_data
			?
				EPOLL_CTL_ADD
			:
				EPOLL_CTL_DEL
			,
			_fd.get(),
			_data
		)
		!= 0
	)
		throw awl::exception(
			FCPPT_TEXT("epoll_ctl failed!")
		);
}
