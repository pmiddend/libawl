#include <awl/system/create.hpp>
#include <awl/system/object_ptr.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <awl/backends/x11/system/object.hpp>
#elif defined(AWL_WINDOWS_BACKEND)
#include <awl/backends/windows/system/object.hpp>
#endif
#include <fcppt/make_shared_ptr.hpp>

awl::system::object_ptr const
awl::system::create()
{
	return 
		fcppt::make_shared_ptr<
#if defined(AWL_X11_BACKEND)
			awl::backends::x11::system::object
#elif defined(AWL_WINDOWS_BACKEND)
			awl::backends::windows::system::object
#endif
		>();
}
