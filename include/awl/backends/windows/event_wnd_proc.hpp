#ifndef AWL_BACKENDS_WINDOWS_EVENT_WND_PROC_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_WND_PROC_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

LRESULT CALLBACK
event_wnd_proc(
	HWND,
	UINT,
	WPARAM,
	LPARAM
);

}
}
}

#endif
