#include <awl/backends/windows/post_message.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>


void
awl::backends::windows::post_message(
	HWND const _hwnd,
	UINT const _msg,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	if(
		PostMessage(
			_hwnd,
			_msg,
			_wparam,
			_lparam
		)
		== 0
	)
		throw awl::exception(
			FCPPT_TEXT("PostMessage() failed!")
		);
}
