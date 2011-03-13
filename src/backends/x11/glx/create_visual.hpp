#ifndef AWL_SRC_BACKENDS_X11_GLX_CREATE_VISUAL_HPP_INCLUDED
#define AWL_SRC_BACKENDS_X11_GLX_CREATE_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual_unique_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace glx
{

x11::visual_unique_ptr
create_visual(
	x11::display &,
	x11::screen,
	int const *attributes
);

}
}
}
}

#endif
