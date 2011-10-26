#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_DESTROY_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_DESTROY_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <fcppt/function/object_fwd.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

typedef fcppt::function::object<
	void(
		HANDLE
	)
> handle_destroy_callback;

}
}
}
}
}

#endif
