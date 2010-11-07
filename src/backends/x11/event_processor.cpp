#include <awl/backends/x11/event_processor.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <awl/backends/x11/event.hpp>
#include <awl/backends/x11/signal/connection.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::x11::event_processor::event_processor(
	x11::window_instance_ptr const _window
)
:
	window_(_window),
	signals_()
{}

awl::backends::x11::event_processor::~event_processor()
{
}

void
awl::backends::x11::event_processor::dispatch()
{
	while(
		x11::optional_event event
			= window_->peek_event()
	)
		signals_[
			event->get().xany.type
		](
			*event
		);
}

awl::backends::x11::signal::unique_connection
awl::backends::x11::event_processor::register_callback(
	int const _event_type,
	x11::event_callback const &_callback
)
{
	return
		signals_[
			_event_type
		].connect(
			_callback,
			std::tr1::bind(
				&event_processor::unregister,
				this,
				_event_type
			)
		);
}

void
awl::backends::x11::event_processor::unregister(
	int const _event_type
)
{
}
