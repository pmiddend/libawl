#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/window/event/function.hpp>
#include <fcppt/function/object.hpp>

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

typedef fcppt::function::object<
	window::event::function	
> callback;

}
}
}
}
}

#endif
