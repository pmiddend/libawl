#include <awl/event/create_processor.hpp>
#include <awl/event/processor.hpp>
#include <awl/event/processor_unique_ptr.hpp>
#include <awl/event/scoped_window_processor.hpp>
#include <awl/main/exit_success.hpp>
#include <awl/system/create.hpp>
#include <awl/system/object.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/system/event/create_processor.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/processor_unique_ptr.hpp>
#include <awl/system/event/optional_processor_ref.hpp>
#include <awl/visual/object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/event/create_processor.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <awl/window/event/show_callback.hpp>
#include <awl/window/event/show_fwd.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <fcppt/config/external_end.hpp>


int
main()
try
{
	awl::system::object_unique_ptr const system(
		awl::system::create()
	);

	awl::visual::object_unique_ptr const visual(
		system->default_visual()
	);

	awl::window::object_unique_ptr const window(
		system->create_window(
			awl::window::parameters(
				*visual
			)
			.class_name(
				FCPPT_TEXT("awlshow")
			)
			.size(
				awl::window::dim(
					1024,
					768
				)
			)
		)
	);

	awl::system::event::processor_unique_ptr const system_processor(
		awl::system::event::create_processor(
			*system
		)
	);

	awl::event::processor_unique_ptr const processor(
		awl::event::create_processor(
			*system,
			awl::system::event::optional_processor_ref(
				*system_processor
			)
		)
	);

	awl::window::event::processor_unique_ptr const window_processor(
		awl::window::event::create_processor(
			*window
		)
	);

	awl::event::scoped_window_processor const scoped_window_processor(
		*processor,
		*window_processor
	);

	window->show();

	fcppt::signal::scoped_connection const show_connection(
		window_processor->show_callback(
			awl::window::event::show_callback(
				[
					&system_processor
				](
					awl::window::event::show const &
				)
				{
					system_processor->quit(
						awl::main::exit_success()
					);
				}
			)
		)
	);

	while(
		system_processor->running()
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

	return
		EXIT_FAILURE;
}
