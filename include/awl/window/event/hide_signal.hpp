#ifndef AWL_WINDOW_EVENT_HIDE_SIGNAL_HPP_INCLUDED
#define AWL_WINDOW_EVENT_HIDE_SIGNAL_HPP_INCLUDED

#include <awl/window/event/hide_function.hpp>
#include <fcppt/signal/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::signal::object<
	awl::window::event::hide_function
> hide_signal;

}
}
}

#endif
