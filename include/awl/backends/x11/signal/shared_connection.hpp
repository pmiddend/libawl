#ifndef AWL_BACKENDS_X11_SIGNAL_SHARED_CONNECTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_SIGNAL_SHARED_CONNECTION_HPP_INCLUDED

#include <awl/backends/x11/signal/connection_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
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

#endif
