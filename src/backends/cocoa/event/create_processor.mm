#include <awl/backends/cocoa/event/create_processor.hpp>
#include <awl/backends/cocoa/event/processor.hpp>
#include <awl/backends/cocoa/system/event/processor.hpp>
#include <awl/backends/cocoa/system/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/static_optional_cast.hpp>
#include <fcppt/cast/static_downcast.hpp>


awl::event::processor_unique_ptr
awl::backends::cocoa::event::create_processor(
	awl::system::object &_system,
	awl::system::event::optional_processor_ref const &_system_processor
)
{
	return
		awl::event::processor_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::cocoa::event::processor
			>(
				fcppt::cast::static_downcast<
					awl::backends::cocoa::system::object &
				>(
					_system
				),
				fcppt::static_optional_cast<
					awl::backends::cocoa::system::event::processor
				>(
					_system_processor
				)
			)
		);
}
