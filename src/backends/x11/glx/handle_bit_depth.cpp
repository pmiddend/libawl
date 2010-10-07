#include "handle_bit_depth.hpp"
#include <awl/exception.hpp>
#include <fcppt/text.hpp>
#include <GL/glx.h>

namespace
{
void
add_bit_depth(
	awl::backends::x11::glx::visual_attribute_array &ret,
	int const r,
	int const g,
	int const b
)
{
	ret.push_back(GLX_RED_SIZE);
	ret.push_back(r);
	ret.push_back(GLX_BLUE_SIZE);
	ret.push_back(g);
	ret.push_back(GLX_GREEN_SIZE);
	ret.push_back(b);
}
}

void
awl::backends::x11::glx::handle_bit_depth(
	visual_attribute_array &ret,
	fcppt::optional<awl::window::bit_depth::type> const &depth)
{
	if (!depth)
		throw exception(FCPPT_TEXT("No bit depth given"));

	switch(*depth)
	{
		case window::bit_depth::depth16:
			add_bit_depth(ret, 5, 6, 5); // TODO: what can we choose from here?
			return;
		case window::bit_depth::depth32:
			add_bit_depth(ret, 8, 8, 8);
			return;
	}
}
