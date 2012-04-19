#include <awl/window/object_fwd.hpp>
#include <awl/window/event/close.hpp>

awl::window::event::close::close(
	window::object &_object
)
:
	object_(_object)
{
}

awl::window::object &
awl::window::event::close::object() const
{
	return object_;
}
