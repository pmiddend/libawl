#include <awl/backends/windows/optional_point.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/client_to_screen.hpp>
#include <awl/backends/windows/window/object.hpp>


awl::backends::windows::optional_point const
awl::backends::windows::window::client_to_screen(
	awl::backends::windows::window::object const &_window,
	POINT const &_point
)
{
	POINT ret(
		_point
	);

	return
		::ClientToScreen(
			_window.hwnd(),
			&ret
		)
		== FALSE
		?
			awl::backends::windows::optional_point()
		:
			awl::backends::windows::optional_point(
				ret
			)
		;
}
