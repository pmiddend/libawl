#include <awl/backends/windows/optional_rect.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/get_rect.hpp>
#include <awl/backends/windows/window/object.hpp>


awl::backends::windows::optional_rect const
awl::backends::windows::window::get_rect(
	awl::backends::windows::window::object const &_object
)
{
	RECT rect;

	return
		::GetWindowRect(
			_object.hwnd(),
			&rect
		)
		== FALSE
		?
			awl::backends::windows::optional_rect()
		:
			awl::backends::windows::optional_rect(
				rect
			)
		;
}
