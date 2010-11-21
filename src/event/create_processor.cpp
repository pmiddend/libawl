#include <awl/event/create_processor.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/original_event_processor.hpp>
#include <awl/backends/x11/window_instance.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/original_event_processor.hpp>
#include <awl/backends/windows/window_instance.hpp>
#endif
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/polymorphic_pointer_cast.hpp>

awl::event::processor_ptr const
awl::event::create_processor(
	awl::window::instance_ptr const _instance
)
{
	return
#if defined(AWL_X11_BACKEND)
		fcppt::make_shared_ptr<
			backends::x11::original_event_processor
		>(
			fcppt::polymorphic_pointer_cast<
				backends::x11::window_instance
			>(
				_instance
			)
		);
#elif defined(AWL_WINDOWS_BACKEND)
		fcppt::make_shared_ptr<
			backends::windows::original_event_processor
		>(
			fcppt::polymorphic_pointer_cast<
				backends::windows::window_instance
			>(
				_instance
			)
		);
#endif
}
