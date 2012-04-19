#ifndef AWL_BACKENDS_X11_WINDOW_OBJECT_SHARED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OBJECT_SHARED_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
#include <fcppt/shared_ptr_impl.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

typedef fcppt::shared_ptr<
	window::object
> object_shared_ptr;

}
}
}
}

#endif
