#ifndef AWL_SRC_BACKENDS_X11_GLX_CREATE_VISUAL_ATTRIBUTES_HPP_INCLUDED
#define AWL_SRC_BACKENDS_X11_GLX_CREATE_VISUAL_ATTRIBUTES_HPP_INCLUDED

#include "visual_attribute_array.hpp"
#include <awl/window/bit_depth.hpp>
#include <awl/window/depth_buffer.hpp>
#include <awl/window/stencil_buffer.hpp>
#include <fcppt/optional.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace glx
{
visual_attribute_array const
create_visual_attributes(
	fcppt::optional<awl::window::bit_depth::type> const &,
	fcppt::optional<awl::window::depth_buffer::type> const &,
	fcppt::optional<awl::window::stencil_buffer::type> const &);
}
}
}
}

#endif
