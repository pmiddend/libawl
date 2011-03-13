#include <awl/system/event/create_processor.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <fcppt/tr1/functional.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <boost/ref.hpp>
#endif
#include <fcppt/make_unique_ptr.hpp>

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
				std::tr1::ref(
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
				boost::ref(
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
