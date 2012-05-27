#include <awl/backends/windows/optional_point.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/screen_to_client.hpp>


awl::backends::windows::optional_point const
awl::backends::windows::window::screen_to_client(
	awl::backends::windows::window::object const &_window,
	POINT const &_point
)
{
	POINT ret(
		_point
	);

	return
		::ScreenToClient(
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
