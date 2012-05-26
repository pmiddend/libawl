#ifndef AWL_WINDOW_EVENT_DESTROY_CALLBACK_FWD_HPP_INCLUDED
#define AWL_WINDOW_EVENT_DESTROY_CALLBACK_FWD_HPP_INCLUDED

#include <awl/window/event/destroy_function.hpp>
#include <fcppt/function/object_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::function::object<
	awl::window::event::destroy_function
> destroy_callback;

}
}
}

#endif