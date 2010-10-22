#include <awl/backends/x11/window_system.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <awl/window/parameters.hpp>

int main()
{
	awl::backends::x11::window_system ws;

	awl::window::instance_ptr wind = 
		ws.create(
			awl::window::parameters());
}
