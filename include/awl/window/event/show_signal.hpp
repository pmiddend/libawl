#ifndef AWL_WINDOW_EVENT_SHOW_SIGNAL_HPP_INCLUDED
#define AWL_WINDOW_EVENT_SHOW_SIGNAL_HPP_INCLUDED

#include <awl/window/event/show_function.hpp>
#include <fcppt/signal/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::signal::object<
	awl::window::event::show_function
> show_signal;

}
}
}

#endif
