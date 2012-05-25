#ifndef AWL_WINDOW_EVENT_CLOSE_CALLBACK_FWD_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CLOSE_CALLBACK_FWD_HPP_INCLUDED

#include <awl/window/event/close_function.hpp>
#include <fcppt/function/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::function::object<
	awl::window::event::close_function
> close_callback;

}
}
}

#endif
