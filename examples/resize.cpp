#include <awl/event/create_processor.hpp>
#include <awl/event/processor.hpp>
#include <awl/event/processor_scoped_ptr.hpp>
#include <awl/event/scoped_window_processor.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_scoped_ptr.hpp>
#include <awl/system/event/optional_processor_ref.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_scoped_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_scoped_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/create_processor.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/processor_scoped_ptr.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/io/cout.hpp>
#include <fcppt/math/dim/output.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace
{

void
print_resize(
	awl::window::event::resize const &_size
)
{
	fcppt::io::cout()
		<< FCPPT_TEXT("Resize: ")
		<< _size.dim()
		<< FCPPT_TEXT('\n');
}

void
window_destroyed(
	awl::window::event::destroy const &,
	bool &_running
)
{
	_running = false;
}

}

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
			.title(
				FCPPT_TEXT("awltest")
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

	awl::event::processor_scoped_ptr const processor(
		awl::event::create_processor(
			*window_system,
			awl::system::event::optional_processor_ref()
		)
	);

	awl::window::event::processor_scoped_ptr const window_processor(
		awl::window::event::create_processor(
			*window
		)
	);

	awl::event::scoped_window_processor const scoped_window_processor(
		*processor,
		*window_processor
	);

	fcppt::signal::scoped_connection const resize_connection(
		window_processor->resize_callback(
			awl::window::event::resize_callback(
				std::bind(
					print_resize,
					std::placeholders::_1
				)
			)
		)
	);

	bool running(
		true
	);

	fcppt::signal::scoped_connection const destroy_connection(
		window_processor->destroy_callback(
			std::bind(
				window_destroyed,
				std::placeholders::_1,
				running
			)
		)
	);

	while(
		running
	)
		processor->next();
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
