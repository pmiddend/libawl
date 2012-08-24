#ifndef AWL_WINDOW_EVENT_SHOW_CALLBACK_FWD_HPP_INCLUDED
#define AWL_WINDOW_EVENT_SHOW_CALLBACK_FWD_HPP_INCLUDED

#include <awl/window/event/show_function.hpp>
#include <fcppt/function/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::function::object<
	awl::window::event::show_function
> show_callback;

}
}
}

#endif
