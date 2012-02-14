#ifndef AWL_WINDOW_EVENT_CLOSE_SIGNAL_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CLOSE_SIGNAL_HPP_INCLUDED

#include <awl/window/event/close_function.hpp>
#include <fcppt/signal/object_fwd.hpp>

namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::signal::object<
	event::close_function
> close_signal;

}
}
}

#endif
