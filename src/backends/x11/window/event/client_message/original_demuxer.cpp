#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/client_message/callback.hpp>
#include <awl/backends/x11/window/event/client_message/object.hpp>
#include <awl/backends/x11/window/event/client_message/original_demuxer.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::client_message::original_demuxer::original_demuxer()
:
	signals_()
{
}

awl::backends::x11::window::event::client_message::original_demuxer::~original_demuxer()
{
}

void
awl::backends::x11::window::event::client_message::original_demuxer::process(
	awl::backends::x11::window::event::object const &_event
)
{
	XClientMessageEvent const &xmessage(
		_event.get().xclient
	);

	signal_map::iterator it(
		signals_.find(
			awl::backends::x11::atom(
				xmessage.message_type
			)
		)
	);

	if(
		it != signals_.end()
	)
		(*it->second)(
			awl::backends::x11::window::event::client_message::object(
				xmessage
			)
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::client_message::original_demuxer::register_callback(
	awl::backends::x11::atom const _atom,
	awl::backends::x11::window::event::client_message::callback const &_callback
)
{
	return
		signals_[
			_atom
		].connect(
			_callback
		);
}
