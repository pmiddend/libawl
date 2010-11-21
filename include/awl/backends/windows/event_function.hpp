#ifndef AWL_BACKENDS_WINDOWS_EVENT_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_FUNCTION_HPP_INCLUDED

#include <awl/backends/windows/event_return_type.hpp>
#include <awl/backends/windows/windows.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

typedef windows::event_return_type
event_function(
	UINT,
	WPARAM,
	LPARAM
);

}
}
}

#endif
