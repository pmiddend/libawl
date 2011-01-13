#include <awl/backends/windows/system/event/timer.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>

awl::backends::windows::system::event::timer::timer(
	UINT const _elapse
)
:
	id_(
		::SetTimer(
			NULL,
			0,
			_elapse,
			NULL
		)
	)
{
	if(
		id_ == 0
	)
		throw awl::exception(
			FCPPT_TEXT("SetTimer() failed!")
		);
}

awl::backends::windows::system::event::timer::~timer()
{
	::KillTimer(
		NULL,
		id()
	);
}

UINT_PTR
awl::backends::windows::system::event::timer::id() const
{
	return id_;
}
