#ifndef AWL_BACKENDS_X11_SIGNAL_SCOPED_CONNECTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_SIGNAL_SCOPED_CONNECTION_HPP_INCLUDED

#include <awl/backends/x11/signal/connection_fwd.hpp>
#include <fcppt/scoped_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace signal
{

typedef fcppt::scoped_ptr<
	signal::connection
> scoped_connection;

}
}
}
}

#endif
