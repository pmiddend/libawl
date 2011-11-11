#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_scoped_ptr.hpp>
#include <awl/window/instance.hpp>
#include <awl/window/instance_scoped_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/chrono/seconds.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/time/sleep_any.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>

int main()
try
{
	awl::system::object_scoped_ptr const window_system(
		awl::system::create()
	);

	awl::window::instance_scoped_ptr const wind(
		window_system->create(
			awl::window::parameters()
			.class_name(
				FCPPT_TEXT("awltest")
			)
			.size(
				awl::window::dim(
					1024,
					768
				)
			)
			.title(
				"Test"
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
catch(
	fcppt::exception const &_exception
)
{
	fcppt::io::cerr()
		<< _exception.string()
		<< FCPPT_TEXT('\n');

	return EXIT_FAILURE;
}
