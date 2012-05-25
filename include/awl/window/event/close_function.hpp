#ifndef AWL_WINDOW_EVENT_CLOSE_FUNCTION_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CLOSE_FUNCTION_HPP_INCLUDED

#include <awl/window/event/close_fwd.hpp>


namespace awl
{
namespace window
{
namespace event
{

typedef
bool
close_function(
	awl::window::event::close const &
);

}
}
}

#endif
