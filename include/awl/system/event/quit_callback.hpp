#ifndef AWL_SYSTEM_EVENT_QUIT_CALLBACK_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_QUIT_CALLBACK_HPP_INCLUDED

#include <awl/system/event/quit_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace system
{
namespace event
{

typedef std::function<
	awl::system::event::quit_function
> quit_callback;

}
}
}

#endif
