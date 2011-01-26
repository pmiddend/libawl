#ifndef AWL_BACKENDS_X11_WINDOW_CLASS_HINT_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_CLASS_HINT_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/class_hint_fwd.hpp>
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
	window::class_hint
> class_hint_ptr;

}
}
}
}

#endif
