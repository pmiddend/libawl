#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle_function.hpp>
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
	system::event::handle_function
> handle_callback;
}
}
}
}
}

#endif
