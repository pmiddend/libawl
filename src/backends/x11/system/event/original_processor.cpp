#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/event/object.hpp>
#include <awl/backends/x11/event/fd/callback.hpp>
#include <awl/backends/x11/event/fd/duration.hpp>
#include <awl/backends/x11/event/fd/epoll.hpp>
#include <awl/backends/x11/event/fd/event.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/quit.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/container/ptr/insert_unique_ptr_map.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/signal/unregister/base_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <sys/epoll.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::system::event::original_processor::original_processor(
	x11::system::object &_system
)
:
	system_(
		_system
	),
	signals_(),
	fd_set_(),
	fd_signals_(),
	scoped_fd_(
		fd_set_,
		awl::backends::x11::display_fd(
			system_.display()
		)
	),
	exit_code_(),
	quit_signal_()
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

	events_processed =
		this->epoll(
			awl::backends::x11::event::fd::duration(
				0
			)
		)
		||
		events_processed
		;

	return events_processed;
}

void
awl::backends::x11::system::event::original_processor::quit(
	awl::main::exit_code const _exit_code
)
{
	exit_code_
		= _exit_code;

	// TODO: can we integrate this in the message loop instead?
	quit_signal_(
		awl::system::event::quit(
			_exit_code
		)
	);
}

bool
awl::backends::x11::system::event::original_processor::running() const
{
	return !exit_code_.has_value();
}

awl::main::exit_code const
awl::backends::x11::system::event::original_processor::exit_code() const
{
	return *exit_code_;
}

fcppt::signal::auto_connection
awl::backends::x11::system::event::original_processor::quit_callback(
	awl::system::event::quit_callback const &_callback
)
{
	return
		quit_signal_.connect(
			_callback
		);
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

fcppt::signal::auto_connection
awl::backends::x11::system::event::original_processor::register_fd_callback(
	awl::backends::x11::event::fd::object const &_fd,
	awl::backends::x11::event::fd::callback const &_callback
)
{
	fd_signal_map::iterator it(
		fd_signals_.find(
			_fd
		)
	);

	if(
		it == fd_signals_.end()
	)
	{
		it =
			fcppt::container::ptr::insert_unique_ptr_map(
				fd_signals_,
				_fd,
				fcppt::make_unique_ptr<
					fd_signal
				>()
			).first;

		fd_set_.add(
			_fd
		);
	}

	return
		it->second->connect(
			_callback,
			std::tr1::bind(
				&awl::backends::x11::system::event::original_processor::unregister_fd_signal,
				this,
				_fd
			)
		);
}

bool
awl::backends::x11::system::event::original_processor::epoll(
	awl::backends::x11::event::fd::duration const &_duration
)
{
	unsigned const ready_fds(
		awl::backends::x11::event::fd::epoll(
			fd_set_,
			_duration
		)
	);

	for(
		int index = 0;
		index < fd_set_.count();
		++index
	)
	{
		epoll_event &event(
			fd_set_.events()[
				index
			]
		);

		if(
			event.events
			& EPOLLIN
		)
		{
			fd_signal_map::iterator const it(
				fd_signals_.find(
					awl::backends::x11::event::fd::object(
						event.data.fd
					)
				)
			);

			if(
				it != fd_signals_.end()
			)
				(*it->second)(
					awl::backends::x11::event::fd::event()
				);
		}
	}

	return
		ready_fds
		!=
		0u;
}

void
awl::backends::x11::system::event::original_processor::process(
	awl::backends::x11::event::object const &_event
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

void
awl::backends::x11::system::event::original_processor::unregister_fd_signal(
	awl::backends::x11::event::fd::object const &_fd
)
{
	fd_signal_map::iterator const it(
		fd_signals_.find(
			_fd
		)
	);

	FCPPT_ASSERT_ERROR(
		it != fd_signals_.end()
	);

	fd_set_.remove(
		_fd
	);

	if(
		it->second->empty()
	)
		fd_signals_.erase(
			it
		);
}
