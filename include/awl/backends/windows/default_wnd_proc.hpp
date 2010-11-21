#ifndef AWL_BACKENDS_WINDOWS_DEFAULT_WND_PROC_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_DEFAULT_WND_PROC_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

LRESULT CALLBACK
default_wnd_proc(
	HWND,
	UINT,
	WPARAM,
	LPARAM
);

}
}
}

#endif
