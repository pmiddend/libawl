#include <awl/backends/x11/event/fd/epoll_ctl.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/event/fd/set.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/algorithm/remove_if.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/data.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/spirit/home/phoenix/bind/bind_member_variable.hpp>
#include <boost/spirit/home/phoenix/core/argument.hpp>
#include <boost/spirit/home/phoenix/operator/comparison.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


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
			_fd.get()
			==
			boost::phoenix::bind(
				&epoll_data::fd,
				boost::phoenix::bind(
					&epoll_event::data,
					boost::phoenix::arg_names::arg1
				)
			)
		)
	);
}

awl::backends::x11::event::fd::object const
awl::backends::x11::event::fd::set::epoll_fd() const
{
	return
		epoll_fd_.get();
}

int
awl::backends::x11::event::fd::set::count() const
{
	return
		static_cast<
			int
		>(
			events_.size()
		);
}

epoll_event *
awl::backends::x11::event::fd::set::events()
{
	return
		fcppt::container::data(
			events_
		);
}
