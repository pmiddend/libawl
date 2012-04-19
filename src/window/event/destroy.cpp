#include <awl/window/object_fwd.hpp>
#include <awl/window/event/destroy.hpp>

awl::window::event::destroy::destroy(
	window::object &_object
)
:
	object_(_object)
{
}

awl::window::object &
awl::window::event::destroy::object() const
{
	return object_;
}
