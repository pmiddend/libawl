#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/x11/system/event/function.hpp>
#include <fcppt/function/object_fwd.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

typedef fcppt::function::object<
	event::function
> callback;

}
}
}
}
}

#endif
