#include <awl/backends/windows/event/post_message.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>


void
awl::backends::windows::event::post_message(
	HWND const _hwnd,
	awl::backends::windows::event::type const _msg,
	awl::backends::windows::event::wparam const _wparam,
	awl::backends::windows::event::lparam const _lparam
)
{
	if(
		PostMessage(
			_hwnd,
			_msg.get(),
			_wparam.get(),
			_lparam.get()
		)
		== 0
	)
		throw awl::exception(
			FCPPT_TEXT("PostMessage() failed!")
		);
}
