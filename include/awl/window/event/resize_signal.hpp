#ifndef AWL_WINDOW_EVENT_RESIZE_SIGNAL_HPP_INCLUDED
#define AWL_WINDOW_EVENT_RESIZE_SIGNAL_HPP_INCLUDED

#include <awl/window/event/resize_function.hpp>
#include <fcppt/signal/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::signal::object<
	awl::window::event::resize_function
> resize_signal;

}
}
}

#endif
