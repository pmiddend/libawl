#include <awl/main/exit_code.hpp>
#include <awl/main/exit_failure.hpp>
#include <awl/config.hpp>
#include <awl/backends/x11/system/original_object.hpp>
#if defined(AWL_X11_BACKEND)
#include <cstdlib>
#endif


awl::main::exit_code const
awl::main::exit_failure()
{
	return
		awl::main::exit_code(
#if defined(AWL_X11_BACKEND)
			EXIT_FAILURE
#elif defined(AWL_WINDOWS_BACKEND)
			0 // TODO: what do we return here?
#else
#error "Don't know what exit_failure should be"
#endif
		);
}
