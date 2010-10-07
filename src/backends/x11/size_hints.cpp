#include <awl/backends/x11/size_hints.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::size_hints::size_hints(
	int const min_w,
	int const min_h,
	int const desired_w,
	int const desired_h)
:
	hints(
		XAllocSizeHints())
{
	if(!hints)
		throw exception(
			FCPPT_TEXT("XAllocSizeHints() failed!"));

	hints->flags = PSize | PMinSize;
	hints->min_width = min_w;
	hints->min_height = min_h;
	hints->base_width = desired_w;
	hints->base_height = desired_h;
}

XSizeHints *
awl::backends::x11::size_hints::get() const
{
	return hints;
}

awl::backends::x11::size_hints::~size_hints()
{
	XFree(hints);
}
