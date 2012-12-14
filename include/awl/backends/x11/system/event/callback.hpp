#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/x11/system/event/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{
namespace event
{

typedef std::function<
	awl::backends::x11::system::event::function
> callback;

}
}
}
}
}

#endif
