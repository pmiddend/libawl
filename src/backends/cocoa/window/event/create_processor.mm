#include <awl/backends/cocoa/window/event/create_processor.hpp>
#include <awl/backends/cocoa/window/event/processor.hpp>
#include <awl/backends/cocoa/window/instance.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/cast/static_downcast.hpp>


awl::window::event::processor_unique_ptr
awl::backends::cocoa::window::event::create_processor(
	awl::window::instance &_instance)
{
	return
		awl::window::event::processor_unique_ptr(
			fcppt::make_unique_ptr<
				backends::cocoa::window::event::processor
			>(
				fcppt::cast::static_downcast<
					backends::cocoa::window::instance &
				>(
					_instance
				)
			)
		);
}
