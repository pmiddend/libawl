#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_ORIGINAL_DEMUXER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CLIENT_MESSAGE_ORIGINAL_DEMUXER_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/backends/x11/window/event/client_message/callback.hpp>
#include <awl/backends/x11/window/event/client_message/demuxer.hpp>
#include <awl/backends/x11/window/event/client_message/function.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <fcppt/config/external_end.hpp>


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

class original_demuxer
{
	FCPPT_NONCOPYABLE(
		original_demuxer
	);
public:
	AWL_SYMBOL
	original_demuxer();

	AWL_SYMBOL
	~original_demuxer();

	AWL_SYMBOL
	void
	process(
		awl::backends::x11::window::event::object const &
	);

	AWL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::x11::atom,
		awl::backends::x11::window::event::client_message::callback const &
	);
private:
	typedef fcppt::signal::object<
		awl::backends::x11::window::event::client_message::function
	> signal;

	typedef boost::ptr_map<
		awl::backends::x11::atom,
		signal
	> signal_map;

	signal_map signals_;
};

}
}
}
}
}
}

#endif
