#ifndef AWL_WINDOW_EVENT_FOCUS_OUT_CALLBACK_FWD_HPP_INCLUDED
#define AWL_WINDOW_EVENT_FOCUS_OUT_CALLBACK_FWD_HPP_INCLUDED

#include <awl/window/event/focus_out_function.hpp>
#include <fcppt/function/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::function::object<
	awl::window::event::focus_out_function
> focus_out_callback;

}
}
}

#endif
