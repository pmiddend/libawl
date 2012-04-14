#include <awl/exception.hpp>
#include <awl/backends/x11/event/fd/duration.hpp>
#include <awl/backends/x11/event/fd/epoll.hpp>
#include <awl/backends/x11/event/fd/set.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/text.hpp>
#include <fcppt/truncation_check_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/chrono/duration.hpp>
#include <sys/epoll.h>
#include <fcppt/config/external_end.hpp>


unsigned
awl::backends::x11::event::fd::epoll(
	awl::backends::x11::event::fd::set &_set,
	awl::backends::x11::event::fd::duration const &_duration
)
{
	int const ret(
		::epoll_wait(
			_set.epoll_fd().get(),
			_set.events(),
			_set.count(),
			fcppt::truncation_check_cast<
				int
			>(
				boost::chrono::duration_cast<
					boost::chrono::milliseconds
				>(
					_duration
				).count()
			)
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
