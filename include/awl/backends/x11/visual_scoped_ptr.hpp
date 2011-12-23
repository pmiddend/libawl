#ifndef AWL_BACKENDS_X11_VISUAL_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/x11/visual_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

typedef fcppt::scoped_ptr<
	x11::visual
> visual_scoped_ptr;

}
}
}

#endif
