#include <awl/backends/x11/free.hpp>
#include <X11/Xlib.h>

void
awl::backends::x11::free(
	void *const _ptr
)
{
	if(
		_ptr != NULL
	)
		::XFree(
			_ptr
		);
}
