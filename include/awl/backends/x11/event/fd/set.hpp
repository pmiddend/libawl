#ifndef AWL_BACKENDS_X11_EVENT_FD_SET_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_SET_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/event/fd/epoll_fd.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/event/fd/optional_duration_fwd.hpp>
#include <awl/backends/x11/event/fd/set_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{
namespace fd
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
		awl::backends::x11::event::fd::object
	);

	AWL_SYMBOL
	void
	remove(
		awl::backends::x11::event::fd::object
	);

	// TODO: replace this by a range!
	AWL_SYMBOL
	unsigned
	epoll(
		awl::backends::x11::event::fd::optional_duration const &
	);

	AWL_SYMBOL
	epoll_event const *
	events() const;
private:
	awl::backends::x11::event::fd::epoll_fd const epoll_fd_;

	typedef std::vector<
		epoll_event
	> event_vector;

	event_vector events_;
};

}
}
}
}
}

#endif
