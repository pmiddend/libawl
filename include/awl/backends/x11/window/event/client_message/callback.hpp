#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_CALLBACK_HPP_INCLUDED

#include <awl/backends/x11/window/event/client_message/function.hpp>
#include <fcppt/function/object.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{
namespace client_message
{

typedef fcppt::function::object<
	awl::backends::x11::window::event::client_message::function
> callback;

}
}
}
}
}
}

#endif
