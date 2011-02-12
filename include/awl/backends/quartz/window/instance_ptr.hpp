#ifndef AWL_BACKENDS_QUARTZ_WINDOW_INSTANCE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_WINDOW_INSTANCE_PTR_HPP_INCLUDED

#include <awl/backends/quartz/window/instance_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace window
{

typedef fcppt::shared_ptr<
	window::instance
> instance_ptr;

}
}
}
}

#endif
