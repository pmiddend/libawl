#include <awl/backends/x11/event/object.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/event/poll.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/signal/auto_connection.hpp>
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
	window_(
		_window
	),
	signals_(),
	mask_counts_(),
	event_mask_(
		0l
	),
	connection_manager_(
		fcppt::assign::make_container<
			fcppt::signal::connection_manager::container
		>(
			fcppt::signal::shared_connection(
				this->register_callback(
					x11::window::event::type(
						ConfigureNotify
					),
					std::tr1::bind(
						&window::event::original_processor::on_configure,
						this,
						std::tr1::placeholders::_1
					)
				)
			)
		)(
			fcppt::signal::shared_connection(
				this->register_callback(
					x11::window::event::type(
						DestroyNotify
					),
					std::tr1::bind(
						&window::event::original_processor::on_destroy,
						this,
						std::tr1::placeholders::_1
					)
				)
			)
		)
	),
	destroy_signal_(),
	resize_signal_()
{
}

awl::backends::x11::window::event::original_processor::~original_processor()
{
}

bool
awl::backends::x11::window::event::original_processor::poll()
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
		this->do_process(
			*new_event
		);

		events_processed = true;
	}

	return events_processed;
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::destroy_callback(
	awl::window::event::destroy_callback const &_callback
)
{
	return
		destroy_signal_.connect(
			_callback
		);
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

awl::backends::x11::window::instance &
awl::backends::x11::window::event::original_processor::x11_window() const
{
	return window_;
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::register_callback(
	x11::window::event::type const _event_type,
	x11::window::event::callback const &_callback
)
{
	if(
		_event_type.get() != ClientMessage
	)
	{
		x11::window::event::mask const new_mask(
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
	}

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
awl::backends::x11::window::event::original_processor::process(
	x11::event::object const &_event
)
{
	this->do_process(
		x11::window::event::object(
			_event.get()
		)
	);
}

void
awl::backends::x11::window::event::original_processor::do_process(
	x11::window::event::object const &_event
)
{
	if(
		event::filter(
			_event,
			window_
		)
	)
		return;

	signals_[
		x11::window::event::type(
			_event.get().type
		)
	](
		_event
	);
}

void
awl::backends::x11::window::event::original_processor::unregister(
	x11::window::event::type const _event_type
)
{
	if(
		_event_type.get() == ClientMessage
	)
		return;

	x11::window::event::mask const old_mask(
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

void
awl::backends::x11::window::event::original_processor::on_destroy(
	x11::window::event::object const &
)
{
	destroy_signal_(
		awl::window::event::destroy(
			window_
		)
	);
}
