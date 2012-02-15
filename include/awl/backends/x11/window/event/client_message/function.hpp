#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_FUNCTION_HPP_INCLUDED

#include <awl/backends/x11/window/event/client_message/object_fwd.hpp>


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

typedef void
function(
	awl::backends::x11::window::event::client_message::object const &
);

}
}
}
}
}
}

#endif
