#include <awl/event/create_processor.hpp>
#include <awl/backends/x11/event_processor.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/polymorphic_pointer_cast.hpp>

awl::event::processor_ptr const
awl::event::create_processor(
	awl::window::instance_ptr const _instance
)
{
	return
		fcppt::make_shared_ptr<
			backends::x11::event_processor
		>(
			fcppt::polymorphic_pointer_cast<
				backends::x11::window_instance
			>(
				_instance
			)
		);
}
