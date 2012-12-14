#ifndef AWL_BACKENDS_X11_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/visual/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

typedef
std::unique_ptr
<
	awl::backends::x11::visual::object
>
object_unique_ptr;

}
}
}
}

#endif
