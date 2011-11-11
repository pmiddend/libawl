#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/event/poll.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/resize.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/signal/shared_connection.hpp>
#include <fcppt/signal/unregister/base_impl.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::original_processor::original_processor(
	x11::window::instance &_window
)
:
	window_(_window),
	signals_(),
	mask_counts_(),
	event_mask_(0l),
	connection_manager_(
		fcppt::assign::make_container<
			fcppt::signal::connection_manager::container
		>(
			fcppt::signal::shared_connection(
				register_callback(
					ConfigureNotify,
					std::tr1::bind(
						&window::event::original_processor::on_configure,
						this,
						std::tr1::placeholders::_1
					)
				)
			)
		)
	)
{
}

awl::backends::x11::window::event::original_processor::~original_processor()
{
}

bool
awl::backends::x11::window::event::original_processor::dispatch()
{
	bool events_processed = false;

	while(
		x11::window::event::optional new_event =
			event::poll(
				window_,
				event_mask_
			)
	)
	{
		if(
			event::filter(
				*new_event,
				window_
			)
		)
			continue;

		signals_[
			new_event->get().type
		](
			*new_event
		);

		events_processed = true;
	}

	return events_processed;
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::resize_callback(
	awl::window::event::resize_callback const &_callback
)
{
	return
		resize_signal_.connect(
			_callback
		);
}

awl::window::instance &
awl::backends::x11::window::event::original_processor::window() const
{
	return window_;
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::register_callback(
	int const _event_type,
	x11::window::event::callback const &_callback
)
{
	long const new_mask(
		x11::window::event::to_mask(
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
		x11::window::event::change_mask(
			window_,
			event_mask_ |= new_mask
		);

	return
		signals_[
			_event_type
		].connect(
			_callback,
			std::tr1::bind(
				&window::event::original_processor::unregister,
				this,
				_event_type
			)
		);
}

void
awl::backends::x11::window::event::original_processor::unregister(
	int const _event_type
)
{
	long const old_mask(
		x11::window::event::to_mask(
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
		x11::window::event::change_mask(
			window_,
			event_mask_ &= ~(old_mask)
		);
}

void
awl::backends::x11::window::event::original_processor::on_configure(
	x11::window::event::object const &_event
)
{
	XConfigureEvent const request(
		_event.get().xconfigure
	);

	resize_signal_(
		awl::window::event::resize(
			window_,
			awl::window::dim(
				request.width,
				request.height
			)
		)
	);
}
