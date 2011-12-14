#include <awl/window/instance_fwd.hpp>
#include <awl/window/event/destroy.hpp>

awl::window::event::destroy::destroy(
	window::instance &_instance
)
:
	instance_(_instance)
{
}

awl::window::instance &
awl::window::event::destroy::instance() const
{
	return instance_;
}
