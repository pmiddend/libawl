#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_FUNCTION_HPP_INCLUDED

#include <awl/backends/windows/window/event/return_type.hpp>
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

typedef windows::window::event::return_type
function(
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
