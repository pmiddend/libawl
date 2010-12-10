#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_UNIQUE_CONNECTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_UNIQUE_CONNECTION_HPP_INCLUDED

#include <awl/backends/x11/window/event/signal/connection_fwd.hpp>
#include <fcppt/unique_ptr.hpp>

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
namespace signal
{

typedef fcppt::unique_ptr<
	signal::connection
> unique_connection;

}
}
}
}
}
}

#endif
