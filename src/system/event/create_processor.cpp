#include <awl/system/event/create_processor.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/event/original_processor.hpp>
#include <awl/backends/windows/system/object.hpp>
#endif
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/polymorphic_pointer_cast.hpp>

awl::system::event::processor_ptr const
awl::system::event::create_processor(
	awl::system::object_ptr const _system
)
{
	return
#if defined(AWL_X11_BACKEND)
		fcppt::make_shared_ptr<
			backends::x11::system::event::original_processor
		>(
			fcppt::polymorphic_pointer_cast<
				backends::x11::system::object
			>(
				_system
			)
		);
#elif defined(AWL_WINDOWS_BACKEND)
		fcppt::make_shared_ptr<
			backends::windows::system::event::original_processor
		>(
			fcppt::polymorphic_pointer_cast<
				backends::windows::system::object
			>(
				_system
			)
		);
#endif
}
