#ifndef AWL_BACKENDS_LINUX_FD_OPTIONAL_DURATION_FWD_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_OPTIONAL_DURATION_FWD_HPP_INCLUDED

#include <awl/backends/linux/fd/duration.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
{

typedef fcppt::optional<
	awl::backends::linux::fd::duration
> optional_duration;

}
}
}
}

#endif
