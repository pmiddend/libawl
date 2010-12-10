#include <awl/backends/x11/window/event/signal/connection_manager.hpp>

awl::backends::x11::window::event::signal::connection_manager::connection_manager(
	container const &_connections
)
:
	connections_(_connections)
{
}

awl::backends::x11::window::event::signal::connection_manager::~connection_manager()
{
}
