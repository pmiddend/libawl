#ifndef AWL_BACKENDS_X11_GLX_HANDLE_BIT_DEPTH_HPP_INCLUDED
#define AWL_BACKENDS_X11_GLX_HANDLE_BIT_DEPTH_HPP_INCLUDED

#include <awl/window/bit_depth.hpp>
#include "visual_attribute_array.hpp"
#include <fcppt/optional.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace glx
{
void
handle_bit_depth(
	visual_attribute_array &,
	fcppt::optional<awl::window::bit_depth::type> const &);
}
}
}
}

#endif
