#include <awl/window/object_fwd.hpp>
#include <awl/window/event/create_processor.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/object.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/window/event/original_processor.hpp>
#include <awl/backends/windows/window/object.hpp>
#elif defined(AWL_COCOA_BACKEND)
#include <awl/backends/cocoa/window/event/create_processor.hpp>
#include <awl/window/event/processor.hpp>
#else
#error "Implement me!"
#endif
#include <fcppt/make_unique_ptr.hpp>


awl::window::event::processor_unique_ptr
awl::window::event::create_processor(
	awl::window::object &_object
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
						backends::x11::window::object &
					>(
						_object
					)
				)
			)
#elif defined(AWL_WINDOWS_BACKEND)
			fcppt::make_unique_ptr<
				backends::windows::window::event::original_processor
			>(
				dynamic_cast<
					backends::windows::window::object &
				>(
					_object
				)
			)
#elif defined(AWL_COCOA_BACKEND)
			backends::cocoa::window::event::create_processor(
					_object)
#else
#error "Implement me!"
#endif
		);
}
