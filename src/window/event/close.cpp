#include <awl/window/instance_fwd.hpp>
#include <awl/window/event/close.hpp>

awl::window::event::close::close(
	window::instance &_instance
)
:
	instance_(_instance)
{
}

awl::window::instance &
awl::window::event::close::instance() const
{
	return instance_;
}
