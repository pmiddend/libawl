#ifndef AWL_BACKENDS_X11_EVENT_FD_EPOLL_FD_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_EPOLL_FD_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/event/fd/epoll_fd_fwd.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <fcppt/noncopyable.hpp>


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

class epoll_fd
{
	FCPPT_NONCOPYABLE(
		epoll_fd
	);
public:
	AWL_SYMBOL
	epoll_fd();

	AWL_SYMBOL
	~epoll_fd();

	awl::backends::x11::event::fd::object const
	get() const;
private:
	awl::backends::x11::event::fd::object const fd_;
};

}
}
}
}
}

#endif
