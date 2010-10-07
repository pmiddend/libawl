#ifndef AWL_SRC_BACKENDS_X11_GLX_CREATE_VISUAL_HPP_INCLUDED
#define AWL_SRC_BACKENDS_X11_GLX_CREATE_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/visual_ptr.hpp>
#include <awl/backends/x11/display_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace glx
{
visual_ptr const
create_visual(
	display_ptr,
	int screen,
	int const *attributes);
}
}
}
}

#endif
