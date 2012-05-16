#include <awl/exception.hpp>
#include <awl/backends/x11/event/fd/epoll_ctl.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/event/fd/object_vector.hpp>
#include <awl/backends/x11/event/fd/optional_duration.hpp>
#include <awl/backends/x11/event/fd/set.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/truncation_check_cast.hpp>
#include <fcppt/container/data.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/duration.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::event::fd::set::set()
:
	epoll_fd_(),
	events_(),
	ready_fds_()
{
}

awl::backends::x11::event::fd::set::~set()
{
}

void
awl::backends::x11::event::fd::set::add(
	awl::backends::x11::event::fd::object const _fd
)
{
	events_.push_back(
		epoll_event()
	);

	awl::backends::x11::event::fd::epoll_ctl(
		epoll_fd_,
		_fd,
		&events_.back()
	);
}

void
awl::backends::x11::event::fd::set::remove(
	awl::backends::x11::event::fd::object const _fd
)
{
	awl::backends::x11::event::fd::epoll_ctl(
		epoll_fd_,
		_fd,
		fcppt::null_ptr()
	);

	events_.pop_back();
}

awl::backends::x11::event::fd::object_vector const &
awl::backends::x11::event::fd::set::epoll(
	awl::backends::x11::event::fd::optional_duration const &_duration
)
{
	int const ret(
		::epoll_wait(
			epoll_fd_.get().get(),
			fcppt::container::data(
				events_
			),
			static_cast<
				int
			>(
				events_.size()
			),
			_duration
			?
				fcppt::truncation_check_cast<
					int
				>(
					boost::chrono::duration_cast<
						boost::chrono::milliseconds
					>(
						*_duration
					).count()
				)
			:
				-1
		)
	);

	if(
		ret == -1
	)
		throw awl::exception(
			FCPPT_TEXT("epoll_wait failed!")
		);

	ready_fds_.clear();

	unsigned const ready(
		static_cast<
			unsigned
		>(
			ret
		)
	);

	for(
		unsigned index = 0;
		index < ready;
		++index
	)
	{
		epoll_event const &event(
			events_[
				index
			]
		);

		if(
			event.events
			& EPOLLIN
		)
			ready_fds_.push_back(
				awl::backends::x11::event::fd::object(
					event.data.fd
				)
			);
	}

	return
		ready_fds_;
}
