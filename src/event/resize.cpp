#include <awl/event/resize.hpp>

awl::event::resize::resize(
	window::instance_ptr const _instance,
	window::dim const &_dim
)
:
	instance_(_instance),
	dim_(_dim)
{
}

awl::window::instance_ptr const
awl::event::resize::instance() const
{
	return instance_;
}

awl::window::dim const &
awl::event::resize::dim() const
{
	return dim_;
}
