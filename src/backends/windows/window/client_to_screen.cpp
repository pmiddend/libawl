#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/client_to_screen.hpp>
#include <awl/backends/windows/window/instance.hpp>
#include <fcppt/text.hpp>


POINT const
awl::backends::windows::window::client_to_screen(
	window::instance const &_window,
	POINT const &_point
)
{
	POINT ret(
		_point
	);

	if(
		::ClientToScreen(
			_window.hwnd(),
			&ret
		)
		== FALSE
	)
		throw awl::exception(
			FCPPT_TEXT("ClientToScreen() failed!")
		);

	return ret;
}
