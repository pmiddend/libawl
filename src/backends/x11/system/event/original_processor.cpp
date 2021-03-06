#include <awl/backends/linux/fd/callback.hpp>
#include <awl/backends/linux/fd/duration.hpp>
#include <awl/backends/linux/fd/event.hpp>
#include <awl/backends/linux/fd/object.hpp>
#include <awl/backends/linux/fd/object_vector.hpp>
#include <awl/backends/linux/fd/optional_duration.hpp>
#include <awl/backends/linux/fd/processor.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <awl/backends/x11/event/object.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/object.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/original_processor.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/quit.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/signal/unregister/base_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <functional>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::system::event::original_processor::original_processor(
	awl::backends::x11::system::object &_system
)
:
	awl::backends::x11::system::event::processor(),
	awl::backends::linux::fd::processor(),
	system_(
		_system
	),
	signals_(),
	fd_set_(),
	fd_signals_(),
	scoped_fd_(
		fd_set_,
		awl::backends::linux::fd::object(
			awl::backends::x11::display_fd(
				system_.display()
			)
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
			awl::backends::x11::event::object(
				xev
			)
		);

		events_processed = true;
	}

	events_processed =
		this->epoll(
			awl::backends::linux::fd::optional_duration(
				awl::backends::linux::fd::duration(
					0
				)
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
	return
		!exit_code_.has_value();
}

awl::main::exit_code const
awl::backends::x11::system::event::original_processor::exit_code() const
{
	FCPPT_ASSERT_ERROR(
		!this->running()
	);

	return
		*exit_code_;
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
	awl::backends::x11::system::event::opcode const &_opcode,
	awl::backends::x11::system::event::type const &_type,
	awl::backends::x11::system::event::callback const &_callback
)
{
	return
		signals_[
			awl::backends::x11::system::event::map_key(
				_opcode,
				_type
			)
		].connect(
			_callback
		);
}

fcppt::signal::auto_connection
awl::backends::x11::system::event::original_processor::register_fd_callback(
	awl::backends::linux::fd::object const &_fd,
	awl::backends::linux::fd::callback const &_callback
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
			fd_signals_.insert(
				std::make_pair(
					_fd,
					fd_signal()
				)
			).first;

		fd_set_.add(
			_fd
		);
	}

	return
		it->second.connect(
			_callback,
			std::bind(
				&awl::backends::x11::system::event::original_processor::unregister_fd_signal,
				this,
				_fd
			)
		);
}

bool
awl::backends::x11::system::event::original_processor::epoll(
	awl::backends::linux::fd::optional_duration const &_duration
)
{
	awl::backends::linux::fd::object_vector const &ready_fds(
		fd_set_.epoll(
			_duration
		)
	);

	for(
		awl::backends::linux::fd::object const &fd
		:
		ready_fds
	)
	{
		fd_signal_map::iterator const map_it(
			fd_signals_.find(
				fd
			)
		);

		if(
			map_it != fd_signals_.end()
		)
			map_it->second(
				awl::backends::linux::fd::event()
			);
	}

	return
		!ready_fds.empty();
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
		awl::backends::x11::system::event::map_key(
			awl::backends::x11::system::event::opcode(
				generic_event.extension
			),
			awl::backends::x11::system::event::type(
				generic_event.evtype
			)
		)
	](
		awl::backends::x11::system::event::object(
			generic_event
		)
	);
}

void
awl::backends::x11::system::event::original_processor::unregister_fd_signal(
	awl::backends::linux::fd::object const &_fd
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
		it->second.empty()
	)
		fd_signals_.erase(
			it
		);
}
