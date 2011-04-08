#include <awl/backends/x11/wrapped_visual.hpp>

awl::backends::x11::wrapped_visual::wrapped_visual(
	Visual &_visual,
	x11::visual_info_unique_ptr _info
)
:
	visual_(_visual),
	info_(
		move(
			_info
		)
	)
{
}
			
awl::backends::x11::wrapped_visual::~wrapped_visual()
{
}

Visual &
awl::backends::x11::wrapped_visual::get() const
{
	return visual_;
}

XVisualInfo &
awl::backends::x11::wrapped_visual::info() const
{
	return *info_;
}
