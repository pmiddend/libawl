#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/client_rect_to_screen.hpp>
#include <awl/backends/windows/window/client_to_screen.hpp>


RECT const
awl::backends::windows::window::client_rect_to_screen(
	window::instance const &_window,
	RECT const &_rect
)
{
	POINT top_left =
	{
		_rect.left,
		_rect.top
	};

	top_left =
		window::client_to_screen(
			_window,
			top_left
		);

	POINT bottom_right =
	{
		_rect.right,
		_rect.bottom
	};

	bottom_right =
		window::client_to_screen(
			_window,
			bottom_right
		);

	RECT const ret = {
		top_left.x,
		top_left.y,
		bottom_right.x,
		bottom_right.y
	};

	return ret;
}
