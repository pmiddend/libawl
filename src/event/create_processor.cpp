#include <awl/event/create_processor.hpp>
#include <awl/event/processor_unique_ptr.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/system/event/optional_processor_ref.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/event/processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <fcppt/cast/static_downcast.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/event/processor.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <fcppt/cast/static_downcast.hpp>
#elif defined(AWL_COCOA_BACKEND)
#include <awl/backends/cocoa/event/create_processor.hpp>
#include <awl/event/processor.hpp>
#endif
#include <fcppt/dynamic_optional_cast.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>

awl::event::processor_unique_ptr
awl::event::create_processor(
	awl::system::object &_system,
	awl::system::event::optional_processor_ref const &_system_processor
)
{
	return
#if defined(AWL_X11_BACKEND)
		awl::event::processor_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::x11::event::processor
			>(
				fcppt::cast::static_downcast<
					awl::backends::x11::system::object &
				>(
					_system
				),
				fcppt::dynamic_optional_cast<
					awl::backends::x11::system::event::processor
				>(
					_system_processor
				)
			)
		)
#elif defined(AWL_WINDOWS_BACKEND)
		awl::event::processor_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::windows::event::processor
			>(
				fcppt::cast::static_downcast<
					awl::backends::windows::system::object &
				>(
					_system
				),
				fcppt::dynamic_optional_cast<
					awl::backends::windows::system::event::processor
				>(
					_system_processor
				)
			)
		)
#elif defined(AWL_COCOA_BACKEND)
			awl::backends::cocoa::event::create_processor(
				_system,
				_system_processor
			)
#endif
			;
}
