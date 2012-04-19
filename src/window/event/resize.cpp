#include <awl/window/dim.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/event/resize.hpp>

awl::window::event::resize::resize(
	window::object &_object,
	window::dim const &_dim
)
:
	object_(_object),
	dim_(_dim)
{
}

awl::window::object &
awl::window::event::resize::object() const
{
	return object_;
}

awl::window::dim const &
awl::window::event::resize::dim() const
{
	return dim_;
}
