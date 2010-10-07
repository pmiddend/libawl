#include <awl/create_window_system.hpp>
#include <awl/window/system_ptr.hpp>
#include <awl/backends/x11/window_system.hpp>
#include <fcppt/make_shared_ptr.hpp>

awl::window::system_ptr const
awl::create_window_system()
{
	return 
		fcppt::make_shared_ptr<awl::backends::x11::window_system>();
}
