#ifndef AWL_BACKENDS_X11_SIGNAL_CONNECTION_MANAGER_HPP_INCLUDED
#define AWL_BACKENDS_X11_SIGNAL_CONNECTION_MANAGER_HPP_INCLUDED

#include <awl/backends/x11/signal/shared_connection.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <vector>

namespace awl
{
namespace backends
{
namespace x11
{
namespace signal
{

class connection_manager
{
	FCPPT_NONCOPYABLE(
		connection_manager
	)
public:
	typedef std::vector<
		signal::shared_connection
	> container;

	AWL_SYMBOL
	explicit connection_manager(
		container const &
	);

	AWL_SYMBOL
	~connection_manager();
private:
	container const connections_;
};

}
}
}
}

#endif
