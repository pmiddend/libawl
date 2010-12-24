#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_WND_PROC_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_WND_PROC_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

LRESULT CALLBACK
wnd_proc(
	HWND,
	UINT,
	WPARAM,
	LPARAM
);

}
}
}
}
}

#endif
