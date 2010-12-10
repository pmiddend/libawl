#include <awl/window/event/resize.hpp>

awl::window::event::resize::resize(
	window::instance_ptr const _instance,
	window::dim const &_dim
)
:
	instance_(_instance),
	dim_(_dim)
{
}

awl::window::instance_ptr const
awl::window::event::resize::instance() const
{
	return instance_;
}

awl::window::dim const &
awl::window::event::resize::dim() const
{
	return dim_;
}
