#ifndef AWL_BACKENDS_X11_WINDOW_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/object_fwd.hpp>
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
	window::object
> object_scoped_ptr;

}
}
}
}

#endif
