#ifndef AWL_WINDOW_EVENT_DESTROY_SIGNAL_HPP_INCLUDED
#define AWL_WINDOW_EVENT_DESTROY_SIGNAL_HPP_INCLUDED

#include <awl/window/event/destroy_function.hpp>
#include <fcppt/signal/object_fwd.hpp>

namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::signal::object<
	event::destroy_function
> destroy_signal;

}
}
}

#endif
