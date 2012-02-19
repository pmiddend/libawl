#include <awl/main/exit_code.hpp>
#include <awl/main/exit_success.hpp>
#include <awl/config.hpp>
#if defined(AWL_X11_BACKEND)
#include <cstdlib>
#endif


awl::main::exit_code const
awl::main::exit_success()
{
	return
		awl::main::exit_code(
#if defined(AWL_X11_BACKEND)
			EXIT_SUCCESS
#elif defined(AWL_WINDOWS_BACKEND)
			0 // TODO: what do we return here?
#else
#error "Don't know what exit_success should be"
#endif
		);
}
