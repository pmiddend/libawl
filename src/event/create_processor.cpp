#include <awl/event/create_processor.hpp>
#include <awl/event/processor_unique_ptr.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/system/event/optional_processor_ref.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/event/processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/event/processor.hpp>
#include <awl/backends/windows/system/object.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#endif
#include <fcppt/cref.hpp>
#include <fcppt/dynamic_optional_cast.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/ref.hpp>

awl::event::processor_unique_ptr
awl::event::create_processor(
	awl::system::object &_system,
	awl::system::event::optional_processor_ref const &_system_processor
)
{
	return
		awl::event::processor_unique_ptr(
#if defined(AWL_X11_BACKEND)
			fcppt::make_unique_ptr<
				awl::backends::x11::event::processor
			>(
				fcppt::ref(
					dynamic_cast<
						awl::backends::x11::system::object &
					>(
						_system
					)
				),
				fcppt::cref(
					fcppt::dynamic_optional_cast<
						awl::backends::x11::system::event::processor
					>(
						_system_processor
					)
				)
			)
#elif defined(AWL_WINDOWS_BACKEND)
			fcppt::make_unique_ptr<
				awl::backends::windows::system::original_object
			>(
				fcppt::ref(
					dynamic_cast<
						awl::backends::windows::system::object &
					>(
						_system
					)
				),
				fcppt::cref(
					fcppt::dynamic_optional_cast<
						awl::backends::windows::system::event::processor
					>(
						_system_processor
					)
				)
			)
#endif
		);
}
