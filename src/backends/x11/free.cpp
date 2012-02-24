#include <awl/backends/x11/free.hpp>
#include <fcppt/null_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

void
awl::backends::x11::free(
	void *const _ptr
)
{
	if(
		_ptr != fcppt::null_ptr()
	)
		::XFree(
			_ptr
		);
}
