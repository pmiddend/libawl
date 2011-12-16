#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/message.hpp>
#include <awl/backends/windows/event/optional_message.hpp>
#include <awl/backends/windows/event/peek.hpp>
#include <fcppt/optional_impl.hpp>


awl::backends::windows::event::optional_message const
awl::backends::windows::event::peek(
	HWND const _hwnd
)
{
	MSG msg;

	return
		::PeekMessage(
			&msg,
			_hwnd,
			0,
			0,
			PM_REMOVE
		)
		== 0
		?
			awl::backends::windows::event::optional_message()
		:
			awl::backends::windows::event::optional_message(
				awl::backends::windows::event::message(
					msg
				)
			);
}
