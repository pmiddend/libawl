#include <awl/window/event/create_processor.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/instance.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/instance.hpp>
#endif
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>

awl::window::event::processor_unique_ptr
awl::window::event::create_processor(
	awl::window::instance &_instance
)
{
	return
		awl::window::event::processor_unique_ptr(
#if defined(AWL_X11_BACKEND)
			fcppt::make_unique_ptr<
				backends::x11::window::event::original_processor
			>(
				fcppt::ref(
					dynamic_cast<
						backends::x11::window::instance &
					>(
						_instance
					)
				)
			)
#elif defined(AWL_WINDOWS_BACKEND)
			fcppt::make_unique_ptr<
				backends::windows::window::event::original_processor
			>(
				fcppt::ref(
					dynamic_cast<
						backends::windows::window::instance &
					>(
						_instance
					)
				)
			)
#endif
		);
}
