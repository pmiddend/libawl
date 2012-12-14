#ifndef AWL_BACKENDS_LINUX_FD_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_CALLBACK_HPP_INCLUDED

#include <awl/backends/linux/fd/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
{

typedef std::function<
	awl::backends::linux::fd::function
> callback;

}
}
}
}

#endif
