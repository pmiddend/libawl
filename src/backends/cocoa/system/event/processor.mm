#include <awl/backends/cocoa/system/event/processor.hpp>
#import <Cocoa/Cocoa.h>

awl::backends::cocoa::system::event::processor::processor()
:
	app_(
		[NSApplication sharedApplication])
{
}

bool
awl::backends::cocoa::system::event::processor::poll()
{
	NSMutableArray *eventArray = [NSMutableArray arrayWithCapacity:1];

	bool got_an_event =
		false;

	while(
		NSEvent *event = 
			[app_
				nextEventMatchingMask:NSAnyEventMask
				untilDate:[NSDate distantPast]
				inMode:NSDefaultRunLoopMode
				dequeue:YES])
	{
		if([event window])
		{
			[eventArray addObject:event];
			continue;
		}

		got_an_event =
			true;

		[app_ sendEvent:event];
		[app_ updateWindows];
	}

	for(NSEvent *e in eventArray)
		[app_ postEvent:e atStart:TRUE];

	return
		got_an_event;
}

awl::backends::cocoa::system::event::processor::~processor()
{
}
