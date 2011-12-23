#ifndef AWL_BACKENDS_X11_WINDOW_INSTANCE_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_INSTANCE_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/instance_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

typedef fcppt::scoped_ptr<
	window::instance
> instance_scoped_ptr;

}
}
}
}

#endif
