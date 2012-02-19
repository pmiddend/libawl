#ifndef AWL_SYSTEM_EVENT_QUIT_CALLBACK_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_QUIT_CALLBACK_HPP_INCLUDED

#include <awl/system/event/quit_function.hpp>
#include <fcppt/function/object.hpp>

namespace awl
{
namespace system
{
namespace event
{

typedef fcppt::function::object<
	awl::system::event::quit_function
> quit_callback;

}
}
}

#endif
