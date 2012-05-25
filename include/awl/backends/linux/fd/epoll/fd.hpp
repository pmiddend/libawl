#ifndef AWL_BACKENDS_LINUX_FD_EPOLL_FD_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_EPOLL_FD_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/epoll/fd_fwd.hpp>
#include <fcppt/noncopyable.hpp>


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

class fd
{
	FCPPT_NONCOPYABLE(
		fd
	);
public:
	AWL_SYMBOL
	fd();

	AWL_SYMBOL
	~fd();

	awl::backends::linux::fd::object const
	get() const;
private:
	awl::backends::linux::fd::object const fd_;
};

}
}
}
}
}

#endif
