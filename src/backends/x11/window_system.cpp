#include <awl/backends/x11/window_system.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <fcppt/make_shared_ptr.hpp>

awl::backends::x11::window_system::window_system()
:
	display_(
		fcppt::make_shared_ptr<display>())
{
}

awl::window::instance_ptr const
awl::backends::x11::window_system::create(
	awl::window::parameters const &p)
{
	return 
		fcppt::make_shared_ptr<window_instance>(
			display_,
			p);
}
