#include <awl/system/create.hpp>
#include <awl/system/object_unique_ptr.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/original_object.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/original_object.hpp>
#elif defined(AWL_COCOA_BACKEND)
#include <awl/backends/cocoa/system/create.hpp>
#else
#error "Don't know how to create a system object"
#endif
#include <fcppt/make_unique_ptr.hpp>

awl::system::object_unique_ptr
awl::system::create()
{
	return
#if defined(AWL_X11_BACKEND)
		awl::system::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::x11::system::original_object
			>()
		);
#elif defined(AWL_WINDOWS_BACKEND)
		awl::system::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::windows::system::original_object
			>()
		);
#elif defined(AWL_COCOA_BACKEND)
			awl::backends::cocoa::system::create();
#else
#error "Don't know how to create a system object"
#endif
}
