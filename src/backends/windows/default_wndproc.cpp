#include <awl/backends/windows/default_wnd_proc.hpp>
#include <awl/backends/windows/windows.hpp>

LRESULT CALLBACK
awl::backends::windows::default_wnd_proc(
	HWND const _hwnd,
	UINT const _msg,
	WPARAM const _wparam,
	LPARAM const _lparam
)
{
	return
		::DefWindowProc(
			_hwnd,
			_msg,
			_wparam,
			_lparam
		);
}
