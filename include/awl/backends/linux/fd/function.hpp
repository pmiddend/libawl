#ifndef AWL_BACKENDS_LINUX_FD_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_FUNCTION_HPP_INCLUDED

#include <awl/backends/linux/fd/event_fwd.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
{

typedef
void
function(
	awl::backends::linux::fd::event const &
);

}
}
}
}

#endif
