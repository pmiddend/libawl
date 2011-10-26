#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/client_rect.hpp>
#include <awl/backends/windows/window/instance.hpp>
#include <fcppt/text.hpp>


RECT const
awl::backends::windows::window::client_rect(
	window::instance const &_instance
)
{
	RECT rect;

	if(
		::GetClientRect(
			_instance.hwnd(),
			&rect
		)
		== FALSE
	)
		throw awl::exception(
			FCPPT_TEXT("GetClientRect() failed!")
		);

	return rect;
}
