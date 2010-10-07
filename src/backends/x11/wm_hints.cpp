#include <awl/backends/x11/wm_hints.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::wm_hints::wm_hints()
:
	hints(
		XAllocWMHints())
{
	if(!hints)
		throw exception(
			FCPPT_TEXT("XAllocWMHints() failed!"));

	hints->input = False;
	hints->initial_state = NormalState;
	hints->flags = InputHint | StateHint;
}

awl::backends::x11::wm_hints::~wm_hints()
{
	XFree(
		hints);
}

XWMHints *
awl::backends::x11::wm_hints::get() const
{
	return hints;
}
