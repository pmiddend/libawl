#include <awl/backends/x11/window/hints.hpp>
#include <awl/backends/x11/free.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::window::hints::hints()
:
	hints_(
		::XAllocWMHints()
	)
{
	if(
		!hints_
	)
		throw awl::exception(
			FCPPT_TEXT("XAllocWMHints() failed!")
		);

	hints_->input = True;

	hints_->initial_state = NormalState;

	hints_->flags = InputHint | StateHint;
}

awl::backends::x11::window::hints::~hints()
{
	x11::free(
		hints_
	);
}

XWMHints *
awl::backends::x11::window::hints::get() const
{
	return hints_;
}
