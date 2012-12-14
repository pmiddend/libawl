#ifndef AWL_WINDOW_EVENT_CLOSE_CALLBACK_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CLOSE_CALLBACK_HPP_INCLUDED

#include <awl/window/event/close_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef std::function<
	awl::window::event::close_function
> close_callback;

}
}
}

#endif
