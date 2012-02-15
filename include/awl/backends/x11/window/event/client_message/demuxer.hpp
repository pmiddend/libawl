#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_DEMUXER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_DEMUXER_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/window/event/client_message/callback.hpp>
#include <awl/backends/x11/window/event/client_message/demuxer_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>


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

class demuxer
{
	FCPPT_NONCOPYABLE(
		demuxer
	);
protected:
	AWL_SYMBOL
	demuxer();
public:
	AWL_SYMBOL
	virtual
	~demuxer() = 0;

	virtual
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::x11::atom,
		awl::backends::x11::window::event::client_message::callback const &
	) = 0;
};

}
}
}
}
}
}

#endif
