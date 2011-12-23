#ifndef AWL_BACKENDS_X11_VISUAL_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/visual_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

typedef
fcppt::unique_ptr
<
	visual
>
visual_unique_ptr;

}
}
}

#endif
