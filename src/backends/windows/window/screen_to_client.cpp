#include <awl/exception.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/screen_to_client.hpp>
#include <fcppt/text.hpp>


POINT const
awl::backends::windows::window::screen_to_client(
	window::object const &_window,
	POINT const &_point
)
{
	POINT ret(
		_point
	);

	if(
		::ScreenToClient(
			_window.hwnd(),
			&ret
		)
		== FALSE
	)
		throw awl::exception(
			FCPPT_TEXT("ScreenToClient() failed!")
		);

	return ret;
}
