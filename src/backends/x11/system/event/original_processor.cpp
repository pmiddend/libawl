#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/event/object.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::system::event::original_processor::original_processor(
	x11::system::object &_system
)
:
	system_(
		_system
	),
	running_(
		true
	),
	signals_()
{
}

awl::backends::x11::system::event::original_processor::~original_processor()
{
}

bool
awl::backends::x11::system::event::original_processor::poll()
{
	bool events_processed = false;

	XEvent xev;

	while(
		::XCheckTypedEvent(
			system_.display().get(),
			GenericEvent,
			&xev
		)
		== True
	)
	{
		this->process(
			x11::event::object(
				xev
			)
		);

		events_processed = true;
	}

	return events_processed;
}

void
awl::backends::x11::system::event::original_processor::quit()
{
	running_ = false;
}

bool
awl::backends::x11::system::event::original_processor::running() const
{
	return running_;
}

fcppt::signal::auto_connection
awl::backends::x11::system::event::original_processor::register_callback(
	x11::system::event::opcode const &_opcode,
	x11::system::event::type const &_type,
	x11::system::event::callback const &_callback
)
{
	return
		signals_[
			event::map_key(
				_opcode,
				_type
			)
		].connect(
			_callback
		);
}

void
awl::backends::x11::system::event::original_processor::process(
	x11::event::object const &_event
)
{
	XGenericEventCookie const &generic_event(
		_event.get().xcookie
	);

	signals_[
		event::map_key(
			event::opcode(
				generic_event.extension
			),
			event::type(
				generic_event.evtype
			)
		)
	](
		system::event::object(
			generic_event
		)
	);
}
