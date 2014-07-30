#include <awl/backends/x11/intern_atom.hpp>
#include <awl/backends/x11/event/object.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/change_mask.hpp>
#include <awl/backends/x11/window/event/filter.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/optional_mask.hpp>
#include <awl/backends/x11/window/event/original_processor.hpp>
#include <awl/backends/x11/window/event/poll_mask.hpp>
#include <awl/backends/x11/window/event/poll_type.hpp>
#include <awl/backends/x11/window/event/to_mask.hpp>
#include <awl/backends/x11/window/event/type.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/event/close.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/focus_in.hpp>
#include <awl/window/event/focus_in_callback.hpp>
#include <awl/window/event/focus_out.hpp>
#include <awl/window/event/focus_out_callback.hpp>
#include <awl/window/event/hide.hpp>
#include <awl/window/event/hide_callback.hpp>
#include <awl/window/event/resize.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/show.hpp>
#include <awl/window/event/show_callback.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/cast/to_unsigned.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/auto_connection_container.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/signal/unregister/base_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xlib.h>
#include <functional>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::event::original_processor::original_processor(
	awl::backends::x11::window::object &_window
)
:
	window_(
		_window
	),
	signals_(),
	mask_counts_(),
	type_counts_(),
	event_mask_(
		0l
	),
	wm_protocols_atom_(
		awl::backends::x11::intern_atom(
			_window.display(),
			"WM_PROTOCOLS"
		)
	),
	wm_delete_window_atom_(
		awl::backends::x11::intern_atom(
			_window.display(),
			"WM_DELETE_WINDOW"
		)
	),
	wm_protocols_(
		_window,
		awl::backends::x11::window::event::atom_vector{
			wm_delete_window_atom_.get()
		}
	),
	close_signal_(
		[](
			bool const _arg1,
			bool const _arg2
		)
		{
			return
				_arg1 && _arg2;
		}
		,
		true
	),
	destroy_signal_(),
	focus_in_signal_(),
	focus_out_signal_(),
	hide_signal_(),
	resize_signal_(),
	show_signal_(),
	connections_(
		fcppt::assign::make_container<
			fcppt::signal::auto_connection_container
		>(
			this->register_callback(
				awl::backends::x11::window::event::type(
					ClientMessage
				),
				std::bind(
					&awl::backends::x11::window::event::original_processor::on_client_message,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				awl::backends::x11::window::event::type(
					ConfigureNotify
				),
				std::bind(
					&awl::backends::x11::window::event::original_processor::on_configure,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				awl::backends::x11::window::event::type(
					DestroyNotify
				),
				std::bind(
					&awl::backends::x11::window::event::original_processor::on_destroy,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				awl::backends::x11::window::event::type(
					FocusIn
				),
				std::bind(
					&awl::backends::x11::window::event::original_processor::on_focus_in,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				awl::backends::x11::window::event::type(
					FocusOut
				),
				std::bind(
					&awl::backends::x11::window::event::original_processor::on_focus_out,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				awl::backends::x11::window::event::type(
					MapNotify
				),
				std::bind(
					&awl::backends::x11::window::event::original_processor::on_map,
					this,
					std::placeholders::_1
				)
			)
		)(
			this->register_callback(
				awl::backends::x11::window::event::type(
					UnmapNotify
				),
				std::bind(
					&awl::backends::x11::window::event::original_processor::on_unmap,
					this,
					std::placeholders::_1
				)
			)
		)
		.move_container()
	)
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
		awl::backends::x11::window::event::optional new_event =
			event::poll_mask(
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

	for(
		auto const &item
		:
		type_counts_
	)
		while(
			awl::backends::x11::window::event::optional new_event =
				awl::backends::x11::window::event::poll_type(
					window_,
					item.first
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
awl::backends::x11::window::event::original_processor::close_callback(
	awl::window::event::close_callback const &_callback
)
{
	return
		close_signal_.connect(
			_callback
		);
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
awl::backends::x11::window::event::original_processor::focus_in_callback(
	awl::window::event::focus_in_callback const &_callback
)
{
	return
		focus_in_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::focus_out_callback(
	awl::window::event::focus_out_callback const &_callback
)
{
	return
		focus_out_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::hide_callback(
	awl::window::event::hide_callback const &_callback
)
{
	return
		hide_signal_.connect(
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

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::show_callback(
	awl::window::event::show_callback const &_callback
)
{
	return
		show_signal_.connect(
			_callback
		);
}

awl::window::object &
awl::backends::x11::window::event::original_processor::window() const
{
	return window_;
}

awl::backends::x11::window::object &
awl::backends::x11::window::event::original_processor::x11_window() const
{
	return window_;
}

fcppt::signal::auto_connection
awl::backends::x11::window::event::original_processor::register_callback(
	awl::backends::x11::window::event::type const _event_type,
	awl::backends::x11::window::event::callback const &_callback
)
{
	awl::backends::x11::window::event::optional_mask const new_mask(
		awl::backends::x11::window::event::to_mask(
			_event_type
		)
	);

	if(
		new_mask
	)
	{
		mask_count const count(
			++mask_counts_[
				*new_mask
			]
		);

		if(
			count == 1u
		)
			awl::backends::x11::window::event::change_mask(
				window_,
				event_mask_ |= *new_mask
			);
	}
	else
		++type_counts_[
			_event_type
		];

	return
		signals_[
			_event_type
		].connect(
			_callback,
			std::bind(
				&awl::backends::x11::window::event::original_processor::unregister,
				this,
				_event_type
			)
		);
}

void
awl::backends::x11::window::event::original_processor::process(
	awl::backends::x11::event::object const &_event
)
{
	this->do_process(
		awl::backends::x11::window::event::object(
			_event.get()
		)
	);
}

void
awl::backends::x11::window::event::original_processor::do_process(
	awl::backends::x11::window::event::object const &_event
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
		awl::backends::x11::window::event::type(
			_event.get().type
		)
	](
		_event
	);
}

void
awl::backends::x11::window::event::original_processor::unregister(
	awl::backends::x11::window::event::type const _event_type
)
{
	awl::backends::x11::window::event::optional_mask const old_mask(
		awl::backends::x11::window::event::to_mask(
			_event_type
		)
	);

	if(
		old_mask
	)
	{
		mask_count const count(
			--mask_counts_[
				*old_mask
			]
		);

		if(
			count == 0u
		)
			awl::backends::x11::window::event::change_mask(
				window_,
				event_mask_ &= ~(*old_mask)
			);
	}
	else
	{
		type_count_map::iterator const it(
			type_counts_.find(
				_event_type
			)
		);

		FCPPT_ASSERT_ERROR(
			it != type_counts_.end()
		);

		if(
			--it->second == 0u
		)
			type_counts_.erase(
				it
			);
	}
}

void
awl::backends::x11::window::event::original_processor::on_client_message(
	awl::backends::x11::window::event::object const &_event
)
{
	XClientMessageEvent const request(
		_event.get().xclient
	);

	if(
		request.message_type
		!=
		wm_protocols_atom_.get()
	)
		return;
	if(
		static_cast<
			Atom
		>(
			request.data.l[0]
		)
		!=
		wm_delete_window_atom_.get()
	)
		return;

	if(
		close_signal_(
			awl::window::event::close()
		)
	)
	{
		window_.destroy();

		destroy_signal_(
			awl::window::event::destroy()
		);
	}
}

void
awl::backends::x11::window::event::original_processor::on_configure(
	awl::backends::x11::window::event::object const &_event
)
{
	XConfigureEvent const request(
		_event.get().xconfigure
	);

	resize_signal_(
		awl::window::event::resize(
			awl::window::dim(
				fcppt::cast::to_unsigned(
					request.width
				),
				fcppt::cast::to_unsigned(
					request.height
				)
			)
		)
	);
}

void
awl::backends::x11::window::event::original_processor::on_destroy(
	awl::backends::x11::window::event::object const &
)
{
	destroy_signal_(
		awl::window::event::destroy()
	);
}

void
awl::backends::x11::window::event::original_processor::on_focus_in(
	awl::backends::x11::window::event::object const &
)
{
	focus_in_signal_(
		awl::window::event::focus_in()
	);
}

void
awl::backends::x11::window::event::original_processor::on_focus_out(
	awl::backends::x11::window::event::object const &
)
{
	focus_out_signal_(
		awl::window::event::focus_out()
	);
}

void
awl::backends::x11::window::event::original_processor::on_map(
	awl::backends::x11::window::event::object const &
)
{
	show_signal_(
		awl::window::event::show()
	);
}

void
awl::backends::x11::window::event::original_processor::on_unmap(
	awl::backends::x11::window::event::object const &
)
{
	hide_signal_(
		awl::window::event::hide()
	);
}
