#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/display.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::system::event::original_processor::original_processor(
	x11::system::object &_system
)
:
	system_(_system)
{
}

awl::backends::x11::system::event::original_processor::~original_processor()
{
}

bool
awl::backends::x11::system::event::original_processor::dispatch()
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
		XGenericEventCookie const &generic_event(
			xev.xcookie
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

		events_processed = true;
	}

	return events_processed;
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
