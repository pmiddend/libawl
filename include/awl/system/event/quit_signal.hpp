#ifndef AWL_SYSTEM_EVENT_QUIT_SIGNAL_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_QUIT_SIGNAL_HPP_INCLUDED

#include <awl/system/event/quit_function.hpp>
#include <fcppt/signal/object_fwd.hpp>


namespace awl
{
namespace system
{
namespace event
{

typedef fcppt::signal::object<
	awl::system::event::quit_function
> quit_signal;

}
}
}

#endif
