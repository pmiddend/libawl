#ifndef AWL_BACKENDS_X11_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/x11/event_function.hpp>
#include <fcppt/function/object_fwd.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

typedef fcppt::function::object<
	event_function
> event_callback;

}
}
}

#endif
