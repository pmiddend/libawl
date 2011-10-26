#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/system/event/original_handle.hpp>
#include <fcppt/text.hpp>


awl::backends::windows::system::event::original_handle::original_handle(
	system::event::handle_destroy_callback const &_on_destroy
)
:
	on_destroy_(_on_destroy),
	handle_(
		::CreateEvent(
			NULL,
			FALSE,
			FALSE,
			NULL
		)
	)
{
	if(
		handle_ == NULL
	)
		throw awl::exception(
			FCPPT_TEXT("CreateEvent() failed!")
		);
}

awl::backends::windows::system::event::original_handle::~original_handle()
{
	::CloseHandle(
		handle_
	);

	on_destroy_(
		handle_
	);
}

HANDLE
awl::backends::windows::system::event::original_handle::get() const
{
	return handle_;
}

bool
awl::backends::windows::system::event::original_handle::ready() const
{
	DWORD const ret(
		::WaitForSingleObject(
			handle_,
			0u
		)
	);

	if(
		ret == WAIT_FAILED
	)
		throw awl::exception(
			FCPPT_TEXT("WaitForSingleObject() failed!")
		);

	return
		ret == WAIT_OBJECT_0;
}
