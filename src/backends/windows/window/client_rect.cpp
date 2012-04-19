#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/client_rect.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <fcppt/text.hpp>


RECT const
awl::backends::windows::window::client_rect(
	window::object const &_object
)
{
	RECT rect;

	if(
		::GetClientRect(
			_object.hwnd(),
			&rect
		)
		== FALSE
	)
		throw awl::exception(
			FCPPT_TEXT("GetClientRect() failed!")
		);

	return rect;
}
