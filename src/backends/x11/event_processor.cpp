#include <awl/backends/x11/event_processor.hpp>
#include <awl/backends/x11/change_event_mask.hpp>
#include <awl/backends/x11/to_event_mask.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <awl/backends/x11/event.hpp>
#include <awl/backends/x11/signal/connection.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::x11::event_processor::event_processor(
	x11::window_instance_ptr const _window
)
:
	window_(_window),
	signals_(),
	mask_counts_(),
	event_mask_(0l)
{}

awl::backends::x11::event_processor::~event_processor()
{
}

void
awl::backends::x11::event_processor::dispatch()
{
	while(
		window_->peek_event()
	)
	{
		x11::event const new_event(
			window_->next_event()
		);

		signals_[
			new_event.get().xany.type
		](
			new_event
		);
	}
}

awl::backends::x11::signal::unique_connection
awl::backends::x11::event_processor::register_callback(
	int const _event_type,
	x11::event_callback const &_callback
)
{
	long const new_mask(
		x11::to_event_mask(
			_event_type
		)
	);

	mask_count const count(
		++mask_counts_[
			new_mask
		]
	);
	
	if(
		count == 1u
	)
		x11::change_event_mask(
			window_,
			event_mask_ |= new_mask
		);

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
	long const old_mask(
		x11::to_event_mask(
			_event_type
		)
	);

	mask_count const count(
		--mask_counts_[
			old_mask
		]
	);

	if(
		count == 0u
	)
		x11::change_event_mask(
			window_,
			event_mask_ &= ~(old_mask)
		);
}
