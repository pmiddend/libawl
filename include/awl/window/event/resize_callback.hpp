#ifndef AWL_WINDOW_EVENT_RESIZE_CALLBACK_HPP_INCLUDED
#define AWL_WINDOW_EVENT_RESIZE_CALLBACK_HPP_INCLUDED

#include <awl/window/event/resize_function.hpp>
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
	awl::window::event::resize_function
> resize_callback;

}
}
}

#endif
