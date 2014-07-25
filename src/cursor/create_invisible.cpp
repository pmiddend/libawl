#include <awl/cursor/create_invisible.hpp>
#include <awl/cursor/object.hpp>
#include <awl/cursor/object_unique_ptr.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/cursor/create_invisible.hpp>
#include <awl/backends/x11/cursor/object.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <fcppt/cast/static_downcast.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/cursor/create_invisible.hpp>
#include <awl/backends/windows/cursor/object.hpp>
#else
#error "Implement me!"
#endif


awl::cursor::object_unique_ptr
awl::cursor::create_invisible(
#if defined(AWL_X11_BACKEND)
	awl::system::object &_system
#else
	awl::system::object &
#endif
)
{
	return
#if defined(AWL_X11_BACKEND)
		awl::backends::x11::cursor::create_invisible(
			fcppt::cast::static_downcast<
				awl::backends::x11::system::object &
			>(
				_system
			).display()
		)
#elif defined(AWL_WINDOWS_BACKEND)
		awl::backends::windows::cursor::create_invisible()
#else
#error "Implement me!"
#endif
		;
}
