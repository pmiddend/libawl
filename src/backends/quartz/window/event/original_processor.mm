#include <awl/backends/quartz/window/event/original_processor.hpp>
#include <awl/backends/quartz/window/instance.hpp>
#include <Cocoa/Cocoa.h>
#include <queue>

awl::backends::quartz::window::event::original_processor::original_processor(
	quartz::window::instance &_window
)
:
	window_(_window)
{
}

awl::backends::quartz::window::event::original_processor::~original_processor()
{
}

bool
awl::backends::quartz::window::event::original_processor::dispatch()
{
	bool events_processed = false;

	NSEvent * event;
	std::queue<
		NSEvent *
	> event_queue;
	NSAutoreleasePool * pool;
	do
	{
		pool = [[NSAutoreleasePool alloc] init];

		// NOTE The window property of the event is undefined for periodic events
		event =
			[NSApp nextEventMatchingMask:
					NSAnyEventMask & !NSPeriodicMask
				untilDate: [NSDate distantPast]
				inMode: NSDefaultRunLoopMode
				dequeue: YES
			];

		if (event)
		{
			events_processed = true;

			if (event.window == window_.get())
			{
				[NSApp sendEvent: event];
			}
			else
			{
				event_queue.push(
					[event retain]
				);
			}
		}

		[pool drain];
	} while (
		event != nil
	);

	// Send back unused events
	while (
		!event_queue.empty()
	)
	{
		event = event_queue.front();
		event_queue.pop();
		[NSApp postEvent: event
			atStart: NO
		];
		[event release];
	}

	return events_processed;
}

fcppt::signal::auto_connection
awl::backends::quartz::window::event::original_processor::resize_callback(
	awl::window::event::resize_callback const &_callback
)
{
	return
		resize_signal_.connect(
			_callback
		);
}

awl::window::instance &
awl::backends::quartz::window::event::original_processor::window() const
{
	return window_;
}
