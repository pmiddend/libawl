#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_remove_callback.hpp>
#include <awl/backends/windows/window/holder.hpp>


awl::backends::windows::window::holder::holder(
	HWND const _hwnd,
	awl::backends::windows::wndclass_remove_callback const &_remove_wndclass
)
:
	hwnd_(
		_hwnd
	),
	remove_wndclass_(
		_remove_wndclass
	)
{
}

awl::backends::windows::window::holder::~holder()
{
	::DestroyWindow(
		hwnd_
	);

	remove_wndclass_();
}

HWND
awl::backends::windows::window::holder::get() const
{
	return
		hwnd_;
}
