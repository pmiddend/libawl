#include <awl/backends/linux/fd/optional_duration.hpp>
#include <awl/backends/linux/fd/processor.hpp>
#include <awl/backends/x11/event/next.hpp>
#include <awl/backends/x11/event/object.hpp>
#include <awl/backends/x11/event/pending.hpp>
#include <awl/backends/x11/event/processor.hpp>
#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/optional_processor_ref.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <X11/X.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::event::processor::processor(
	awl::backends::x11::system::object &_system,
	awl::backends::x11::system::event::optional_processor_ref const &_system_processor
)
:
	system_(
		_system
	),
	system_processor_(
		_system_processor
	),
	window_processors_()
{
}

awl::backends::x11::event::processor::~processor()
{
}

bool
awl::backends::x11::event::processor::poll()
{
	// events might come in any order
	// so make sure to process as much as possible in one go
	bool events_processed = false;

	bool more_messages = true;

	while(
		more_messages
	)
	{
		if(
			system_processor_
		)
			more_messages =
				system_processor_->poll();

		for(
			auto &entry : window_processors_
		)
			more_messages =
				entry.second->poll()
				||
				more_messages;

		if(
			more_messages
		)
			events_processed = true;
		else
			break;
	}

	return events_processed;
}

void
awl::backends::x11::event::processor::next()
{
	if(
		system_processor_
	)
	{
		if(
			!system_processor_->running()
		)
			return;

		if(
			awl::backends::linux::fd::processor *linux_processor =
				dynamic_cast<
					awl::backends::linux::fd::processor *
				>(
					&*system_processor_
				)
		)
		{
			linux_processor->epoll(
				awl::backends::linux::fd::optional_duration()
			);

			if(
				!awl::backends::x11::event::pending(
					system_.display()
				)
			)
				return;
		}
	}

	x11::event::object const event(
		x11::event::next(
			system_.display()
		)
	);

	if(
		event.get().type
		==
		GenericEvent
	)
	{
		if(
			system_processor_
		)
			system_processor_->process(
				event
			);

		return;
	}

	window_processor_map::iterator const it(
		window_processors_.find(
			event.get().xany.window
		)
	);

	if(
		it != window_processors_.end()
	)
		it->second->process(
			event
		);
}

void
awl::backends::x11::event::processor::attach(
	awl::window::event::processor &_processor
)
{
	awl::backends::x11::window::event::processor &x11_processor(
		dynamic_cast<
			awl::backends::x11::window::event::processor &
		>(
			_processor
		)
	);

	FCPPT_ASSERT_ERROR((
		window_processors_.insert(
			std::make_pair(
				x11_processor.x11_window().get(),
				&x11_processor
			)
		).second
	));
}

void
awl::backends::x11::event::processor::detach(
	awl::window::event::processor &_processor
)
{
	FCPPT_ASSERT_ERROR(
		window_processors_.erase(
			dynamic_cast<
				awl::backends::x11::window::event::processor &
			>(
				_processor
			).x11_window().get()
		) == 1u
	);
}
