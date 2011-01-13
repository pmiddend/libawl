#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/system/event/function.hpp>
#include <fcppt/function/object.hpp>

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
	windows::system::event::function	
> callback;

}
}
}
}
}

#endif
