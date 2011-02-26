#include <awl/backends/quartz/event_manager.hpp>
#import <Cocoa/Cocoa.h>

awl::backends::quartz::event_manager::window_event_map
awl::backends::quartz::event_manager::event_buffer_;

void
awl::backends::quartz::event_manager::fetch_and_buffer_events()
{
	NSEvent * event;
	while ((
		event
		=
		[[NSApplication sharedApplication]
			nextEventMatchingMask: NSAnyEventMask
				untilDate:
					[NSDate distantPast]
				inMode: NSDefaultRunLoopMode
				dequeue: YES
		]
   ))
   {
		// [event window] is undefined for periodic events. We store them with the
		// system events
		if (
				[event type]
				==
				NSPeriodic
			||
				[event window]
				==
				nil
		)
		{
			event_buffer_[NULL].push(event);
		}
		else
		{
			event_buffer_[[event window]].push(event);
		}
   }
}

bool
awl::backends::quartz::event_manager::dispatch_events_for_window(window_ref const window_or_null)
{
	fetch_and_buffer_events();

	bool events_dispatched = false;
	event_queue queue = event_buffer_[window_or_null];
	while (
		!queue.empty()
	)
	{
		events_dispatched = true;
		[NSApp sendEvent:(NSEvent *) queue.front()];
		queue.pop();
	}

	return events_dispatched;
}
