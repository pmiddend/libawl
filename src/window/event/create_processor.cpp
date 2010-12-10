#include <awl/window/event/create_processor.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/instance.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/instance.hpp>
#endif
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/polymorphic_pointer_cast.hpp>

awl::window::event::processor_ptr const
awl::window::event::create_processor(
	awl::window::instance_ptr const _instance
)
{
	return
#if defined(AWL_X11_BACKEND)
		fcppt::make_shared_ptr<
			backends::x11::window::event::original_processor
		>(
			fcppt::polymorphic_pointer_cast<
				backends::x11::window::instance
			>(
				_instance
			)
		);
#elif defined(AWL_WINDOWS_BACKEND)
		fcppt::make_shared_ptr<
			backends::windows::window::event::original_processor
		>(
			fcppt::polymorphic_pointer_cast<
				backends::windows::window::instance
			>(
				_instance
			)
		);
#endif
}
