#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/window/instance.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/time/sleep_any.hpp>
#include <fcppt/chrono/seconds.hpp>

int main()
{
	awl::system::object_ptr const window_system(
		awl::system::create()
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
