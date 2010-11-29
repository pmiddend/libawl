#include <awl/window/create_system.hpp>
#include <awl/window/system.hpp>
#include <awl/window/instance.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/time/sleep_any.hpp>
#include <fcppt/chrono/seconds.hpp>

int main()
{
	awl::window::system_ptr const window_system(
		awl::window::create_system()
	);

	awl::window::instance_ptr const wind(
		window_system->create(
			awl::window::parameters()
			.size(
				awl::window::dim(
					1024,
					768
				)
			)
		)
	);
	
	wind->show();

	fcppt::time::sleep_any(
		fcppt::chrono::seconds(
			1
		)
	);
}
