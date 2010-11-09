#include "create_visual_attributes.hpp"
#include "handle_bit_depth.hpp"
#include <GL/glx.h>

awl::backends::x11::glx::visual_attribute_array const
awl::backends::x11::glx::create_visual_attributes(
	fcppt::optional<awl::window::bit_depth::type> const &bit_depth,
	fcppt::optional<awl::window::depth_buffer::type> const &depth_buffer,
	fcppt::optional<awl::window::stencil_buffer::type> const &stencil_buffer)
{
	visual_attribute_array ret;

	ret.push_back(
		GLX_RGBA);
	ret.push_back(
		GLX_DOUBLEBUFFER);

	glx::handle_bit_depth(
		ret,
		bit_depth);

	if(depth_buffer && *depth_buffer != awl::window::depth_buffer::off)
	{
		ret.push_back(
			GLX_DEPTH_SIZE);
		ret.push_back(
			static_cast<int>(
				*depth_buffer)); // TODO
	}

	if(stencil_buffer && *stencil_buffer != awl::window::stencil_buffer::off)
	{
		ret.push_back(
			GLX_STENCIL_SIZE);
		ret.push_back(
			static_cast<int>(*stencil_buffer)); // TODO
	}

	ret.push_back(
		None);

	return ret;
}
