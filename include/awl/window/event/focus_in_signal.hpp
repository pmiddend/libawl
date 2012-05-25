#ifndef AWL_WINDOW_EVENT_FOCUS_IN_SIGNAL_HPP_INCLUDED
#define AWL_WINDOW_EVENT_FOCUS_IN_SIGNAL_HPP_INCLUDED

#include <awl/window/event/focus_in_function.hpp>
#include <fcppt/signal/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::signal::object<
	awl::window::event::focus_in_function
> focus_in_signal;

}
}
}

#endif
