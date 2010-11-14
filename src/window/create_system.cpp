#include <awl/window/create_system.hpp>
#include <awl/window/system_ptr.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/window_system.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/window_system.hpp>
#endif
#include <fcppt/make_shared_ptr.hpp>

awl::window::system_ptr const
awl::window::create_system()
{
	return 
		fcppt::make_shared_ptr<
#if defined(AWL_X11_BACKEND)
			awl::backends::x11::window_system
#elif defined(AWL_WINDOWS_BACKEND)
			awl::backends::windows::window_system
#endif
		>();
}
