#ifndef AWL_BACKENDS_WINDOWS_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/event_function.hpp>
#include <fcppt/function/object.hpp>

namespace awl
{
namespace backends
{
namespace windows
{

typedef fcppt::function::object<
	event_function	
> event_callback;

}
}
}

#endif
