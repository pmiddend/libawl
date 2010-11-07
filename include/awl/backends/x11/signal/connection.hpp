#ifndef AWL_BACKENDS_X11_SIGNAL_CONNECTION_HPP_INCLUDED
#define AWL_BACKENDS_X11_SIGNAL_CONNECTION_HPP_INCLUDED

#include <awl/backends/x11/signal/connection_fwd.hpp>
#include <awl/backends/x11/signal/unregister_callback.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace signal
{

class connection
{
	FCPPT_NONCOPYABLE(
		connection
	)
public:
	AWL_SYMBOL
	connection(
		fcppt::signal::auto_connection,
		signal::unregister_callback const &
	);

	AWL_SYMBOL
	~connection();
private:
	fcppt::signal::scoped_connection const connection_;

	signal::unregister_callback const callback_;	
};

}
}
}
}

#endif
