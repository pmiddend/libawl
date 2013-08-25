#include <awl/backends/windows/event/get.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/message.hpp>
#include <awl/backends/windows/event/object.hpp>
#include <awl/backends/windows/event/optional_message.hpp>
#include <awl/backends/windows/event/peek.hpp>
#include <awl/backends/windows/event/processor.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/system/object_fwd.hpp>
#include <awl/backends/windows/system/event/optional_processor_ref.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/window/object.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <utility>
#include <fcppt/config/external_end.hpp>


awl::backends::windows::event::processor::processor(
	awl::backends::windows::system::object &,
	awl::backends::windows::system::event::optional_processor_ref const &_system_processor
)
:
	system_processor_(
		_system_processor
	),
	window_processors_()
{
}

awl::backends::windows::event::processor::~processor()
{
}

bool
awl::backends::windows::event::processor::poll()
{
	bool events_processed(
		this->poll_messages()
	);

	if(
		system_processor_
	)
		events_processed =
			system_processor_->poll_handles()
			|| events_processed;

	return events_processed;
}

void
awl::backends::windows::event::processor::next()
{
	if(
		!system_processor_
	)
		this->do_process(
			windows::event::get()
		);
	else
	{
		system_processor_->next();

		this->poll_messages();
	}
}

void
awl::backends::windows::event::processor::attach(
	awl::window::event::processor &_processor
)
{
	awl::backends::windows::window::event::processor &windows_processor(
		fcppt::cast::static_downcast<
			awl::backends::windows::window::event::processor &
		>(
			_processor
		)
	);

	FCPPT_ASSERT_ERROR(
		window_processors_.insert(
			std::make_pair(
				windows_processor.windows_window().hwnd(),
				&windows_processor
			)
		).second
	);
}

void
awl::backends::windows::event::processor::detach(
	awl::window::event::processor &_processor
)
{
	FCPPT_ASSERT_ERROR(
		window_processors_.erase(
			fcppt::cast::static_downcast<
				awl::backends::windows::window::event::processor &
			>(
				_processor
			).windows_window().hwnd()
		)
		== 1u
	);
}

void
awl::backends::windows::event::processor::do_process(
	awl::backends::windows::event::message const &_msg
)
{

	if(
		_msg.get().hwnd == NULL
	)
	{
		if(
			system_processor_
		)
			system_processor_->process(
				awl::backends::windows::event::object(
					awl::backends::windows::event::type(
						_msg.get().message
					),
					awl::backends::windows::event::wparam(
						_msg.get().wParam
					),
					awl::backends::windows::event::lparam(
						_msg.get().lParam
					)
				)
			);

		return;
	}

	window_processor_map::iterator const it(
		window_processors_.find(
			_msg.get().hwnd
		)
	);

	if(
		it != window_processors_.end()
	)
		it->second->process(
			_msg
		);
}

bool
awl::backends::windows::event::processor::poll_messages()
{
	bool events_processed = false;

	while(
		windows::event::optional_message const message =
			windows::event::peek(
				NULL
			)
	)
	{
		events_processed = true;

		this->do_process(
			*message
		);
	}

	return events_processed;
}
