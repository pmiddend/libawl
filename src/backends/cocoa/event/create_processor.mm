#include <awl/backends/cocoa/event/create_processor.hpp>
#include <awl/backends/cocoa/event/processor.hpp>
#include <awl/backends/cocoa/system/event/processor.hpp>
#include <awl/backends/cocoa/system/object.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/cref.hpp>
#include <fcppt/dynamic_optional_cast.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>

awl::event::processor_unique_ptr
awl::backends::cocoa::event::create_processor(
	awl::system::object &_system,
	awl::system::event::optional_processor_ref const &_system_processor)
{
	return
		awl::event::processor_unique_ptr(
			fcppt::make_unique_ptr<awl::backends::cocoa::event::processor>(
				fcppt::ref(
					dynamic_cast<awl::backends::cocoa::system::object &>(
						_system)),
				fcppt::cref(
					fcppt::dynamic_optional_cast<awl::backends::cocoa::system::event::processor>(
						_system_processor))));
}
