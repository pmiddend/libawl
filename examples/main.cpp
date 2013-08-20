#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_scoped_ptr.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_scoped_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_scoped_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/time/sleep_any.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <chrono>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

int
main()
try
{
	awl::system::object_scoped_ptr const window_system(
		awl::system::create()
	);

	awl::visual::object_scoped_ptr const visual(
		window_system->default_visual()
	);

	awl::window::object_scoped_ptr const window(
		window_system->create_window(
			awl::window::parameters(
				*visual
			)
			.class_name(
				FCPPT_TEXT("awltest")
			)
			.size(
				awl::window::dim(
					1024,
					768
				)
			)
		)
	);

	window->show();

	fcppt::time::sleep_any(
		std::chrono::seconds(
			1
		)
	);
}
catch(
	fcppt::exception const &_exception
)
{
	fcppt::io::cerr()
		<< _exception.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
