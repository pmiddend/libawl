#include <awl/exception.hpp>
#include <awl/backends/x11/event/fd/epoll_ctl.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/event/fd/optional_duration.hpp>
#include <awl/backends/x11/event/fd/set.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/truncation_check_cast.hpp>
#include <fcppt/algorithm/remove_if.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/data.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/duration.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


namespace
{

class find_event
{
	FCPPT_NONASSIGNABLE(
		find_event
	);
public:
	explicit
	find_event(
		awl::backends::x11::event::fd::object
	);

	bool
	operator()(
		epoll_event const &
	) const;
private:
	awl::backends::x11::event::fd::object const fd_;
};

}

awl::backends::x11::event::fd::set::set()
:
	epoll_fd_(),
	events_()
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

	FCPPT_ASSERT_ERROR(
		fcppt::algorithm::remove_if(
			events_,
			find_event(
				_fd
			)
		)
	);
}

unsigned
awl::backends::x11::event::fd::set::epoll(
	awl::backends::x11::event::fd::optional_duration const &_duration
)
{
	for(
		event_vector::iterator it(
			events_.begin()
		);
		it != events_.end();
		++it
	)
		it->events = 0;

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

	return
		static_cast<
			unsigned
		>(
			ret
		);
}

epoll_event const *
awl::backends::x11::event::fd::set::events() const
{
	return
		fcppt::container::data(
			events_
		);
}

namespace
{

find_event::find_event(
	awl::backends::x11::event::fd::object const _fd
)
:
	fd_(
		_fd
	)
{
}

bool
find_event::operator()(
	epoll_event const &_event
) const
{
	return
		_event.data.fd
		==
		fd_.get();
}

}
