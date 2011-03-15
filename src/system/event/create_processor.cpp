#include <awl/system/event/create_processor.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/object.hpp>
#endif
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>

awl::system::event::processor_unique_ptr
awl::system::event::create_processor(
	awl::system::object &_system
)
{
	return
		awl::system::event::processor_unique_ptr(
#if defined(AWL_X11_BACKEND)
			fcppt::make_unique_ptr<
				backends::x11::system::event::original_processor
			>(
				fcppt::ref(
					dynamic_cast<
						backends::x11::system::object &
					>(
						_system
					)
				)
			)
#elif defined(AWL_WINDOWS_BACKEND)
			fcppt::make_unique_ptr<
				backends::windows::system::event::original_processor
			>(
				fcppt::ref(
					dynamic_cast<
						backends::windows::system::object &
					>(
						_system
					)
				)
			)
#endif
		);
}
