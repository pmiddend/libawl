#include <awl/backends/x11/event_processor.hpp>
#include <awl/backends/x11/change_event_mask.hpp>
#include <awl/backends/x11/to_event_mask.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <awl/backends/x11/event.hpp>
#include <awl/backends/x11/signal/connection.hpp>
#include <awl/backends/x11/signal/shared_connection.hpp>
#include <awl/event/resize.hpp>
#include <awl/window/dim.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/optional_impl.hpp>
#include <X11/Xlib.h>

awl::backends::x11::event_processor::event_processor(
	x11::window_instance_ptr const _window
)
:
	window_(_window),
	signals_(),
	mask_counts_(),
	event_mask_(0l),
	connection_manager_(
		fcppt::assign::make_container<
			x11::signal::connection_manager::container
		>(
			x11::signal::shared_connection(
				register_callback(
					ConfigureNotify,
					std::tr1::bind(
						&event_processor::on_configure,
						this,
						std::tr1::placeholders::_1
					)
				)
			)
		)
		(
			x11::signal::shared_connection(
				register_callback(
					ResizeRequest,
					std::tr1::bind(
						&event_processor::on_resize,
						this,
						std::tr1::placeholders::_1
					)
				)
			)
		)
	)
{}

awl::backends::x11::event_processor::~event_processor()
{
}

void
awl::backends::x11::event_processor::dispatch()
{
	while(
		x11::optional_event new_event =
			window_->poll_event(
				event_mask_
			)
	)
	{
		if(
			::XFilterEvent(
				&new_event->get(),
				window_->get()
			)
			== True
		)
			continue;

		signals_[
			new_event->get().xany.type
		](
			*new_event
		);
	}
}

fcppt::signal::auto_connection
awl::backends::x11::event_processor::resize_callback(
	awl::event::resize_callback const &_callback
)
{
	return
		resize_signal_.connect(
			_callback
		);
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

void
awl::backends::x11::event_processor::on_configure(
	x11::event const &_event
)
{
	XConfigureEvent const request(
		_event.get().xconfigure
	);

	resize_signal_(
		awl::event::resize(
			window_,
			awl::window::dim(
				request.width,
				request.height
			)
		)
	);
}

void
awl::backends::x11::event_processor::on_resize(
	x11::event const &_event
)
{
	XResizeRequestEvent const &request(
		_event.get().xresizerequest
	);

	resize_signal_(
		awl::event::resize(
			window_,
			awl::window::dim(
				request.width,
				request.height
			)
		)
	);
}
