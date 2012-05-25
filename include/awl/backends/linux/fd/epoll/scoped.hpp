#ifndef AWL_BACKENDS_LINUX_FD_EPOLL_SCOPED_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_EPOLL_SCOPED_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/epoll/set_fwd.hpp>
#include <awl/backends/linux/fd/epoll/scoped_fwd.hpp>
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

class scoped
{
	FCPPT_NONCOPYABLE(
		scoped
	);
public:
	AWL_SYMBOL
	scoped(
		awl::backends::linux::fd::epoll::set &,
		awl::backends::linux::fd::object
	);

	AWL_SYMBOL
	~scoped();
private:
	awl::backends::linux::fd::epoll::set &set_;

	awl::backends::linux::fd::object const fd_;
};

}
}
}
}
}

#endif
