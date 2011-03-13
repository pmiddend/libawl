#ifndef AWL_BACKENDS_X11_WINDOW_INSTANCE_SHARED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_INSTANCE_SHARED_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/instance_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

typedef fcppt::shared_ptr<
	window::instance
> instance_shared_ptr;

}
}
}
}

#endif
