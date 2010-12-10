#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_SHARED_CONNECTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_SHARED_CONNECTION_HPP_INCLUDED

#include <awl/backends/x11/window/event/signal/connection_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

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

typedef fcppt::shared_ptr<
	signal::connection
> shared_connection;

}
}
}
}
}
}

#endif
