#ifndef AWL_BACKENDS_X11_VISUAL_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/x11/visual/object_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

typedef fcppt::scoped_ptr<
	awl::backends::x11::visual::object
> object_scoped_ptr;

}
}
}
}

#endif
