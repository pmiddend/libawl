#include <awl/backends/quartz/system/event/original_processor.hpp>
#include <Cocoa/Cocoa.h>
#include <queue>

awl::backends::quartz::system::event::original_processor::original_processor(
	quartz::system::object &_system
)
{
}

awl::backends::quartz::system::event::original_processor::~original_processor()
{
}

bool
awl::backends::quartz::system::event::original_processor::dispatch()
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

		event =
			[NSApp nextEventMatchingMask: NSAnyEventMask
				untilDate: [NSDate distantPast]
				inMode: NSDefaultRunLoopMode
				dequeue: YES
			];

		if (event)
		{
			events_processed = true;

			if (event.window == nil)
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
