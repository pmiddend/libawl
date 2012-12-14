#ifndef AWL_WINDOW_EVENT_SHOW_CALLBACK_HPP_INCLUDED
#define AWL_WINDOW_EVENT_SHOW_CALLBACK_HPP_INCLUDED

#include <awl/window/event/show_function.hpp>
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
	awl::window::event::show_function
> show_callback;

}
}
}

#endif
