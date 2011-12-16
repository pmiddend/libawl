#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/get.hpp>
#include <awl/backends/windows/event/message.hpp>
#include <fcppt/text.hpp>

awl::backends::windows::event::message const
awl::backends::windows::event::get()
{
	MSG msg;

	if(
		::GetMessage(
			&msg,
			NULL,
			0,
			0
		)
		== -1
	)
		throw awl::exception(
			FCPPT_TEXT("GetMessage() failed!")
		);

	return
		awl::backends::windows::event::message(
			msg
		);
}
