#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/window/common_object.hpp>
#include <awl/backends/windows/window/wrapped_object.hpp>


awl::backends::windows::window::wrapped_object::wrapped_object(
	HWND const _hwnd
)
:
	awl::backends::windows::window::common_object(),
	hwnd_(
		_hwnd
	)
{
}

awl::backends::windows::window::wrapped_object::~wrapped_object()
{
}

HWND
awl::backends::windows::window::wrapped_object::hwnd() const
{
	return
		hwnd_;
}
