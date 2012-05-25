#ifndef AWL_BACKENDS_LINUX_FD_EPOLL_SET_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_EPOLL_SET_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/object_vector.hpp>
#include <awl/backends/linux/fd/optional_duration_fwd.hpp>
#include <awl/backends/linux/fd/epoll/fd.hpp>
#include <awl/backends/linux/fd/epoll/set_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <vector>
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

class set
{
	FCPPT_NONCOPYABLE(
		set
	);
public:
	AWL_SYMBOL
	set();

	AWL_SYMBOL
	~set();

	AWL_SYMBOL
	void
	add(
		awl::backends::linux::fd::object
	);

	AWL_SYMBOL
	void
	remove(
		awl::backends::linux::fd::object
	);

	AWL_SYMBOL
	awl::backends::linux::fd::object_vector const &
	epoll(
		awl::backends::linux::fd::optional_duration const &
	);
private:
	awl::backends::linux::fd::epoll::fd const epoll_fd_;

	typedef std::vector<
		epoll_event
	> event_vector;

	event_vector events_;

	awl::backends::linux::fd::object_vector ready_fds_;
};

}
}
}
}
}

#endif
