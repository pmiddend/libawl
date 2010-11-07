#ifndef AWL_BACKENDS_X11_SIGNAL_UNIQUE_CONNECTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_SIGNAL_UNIQUE_CONNECTION_HPP_INCLUDED

#include <awl/backends/x11/signal/connection_fwd.hpp>
#include <fcppt/unique_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
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

#endif
