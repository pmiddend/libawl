#include <awl/backends/quartz/system/original_object.hpp>
#include <awl/backends/quartz/window/original_instance.hpp>
#include <awl/window/parameters.hpp>
#import <Cocoa/Cocoa.h>
#include <fcppt/assert.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <queue>

awl::backends::quartz::system::original_object::original_object()
:
	autorelease_pool_(
		[[NSAutoreleasePool alloc] init]
	)
{
	// Initializes display server for this application
	// and creates the global NSAppplication object NSApp
	[NSApplication sharedApplication];
	[NSApp finishLaunching];
	//[NSApp activateIgnoringOtherApps:NO]; // Not necessary AFAIK

	// This stops the dock icon from jumping
	event_loop();
}

awl::backends::quartz::system::original_object::~original_object()
{
	// Release dangling pointers, basically
	[(NSAutoreleasePool *) autorelease_pool_ drain];
}

awl::window::instance_ptr const
awl::backends::quartz::system::original_object::create(
	awl::window::parameters const &_param
)
{
	// TODO Copied from x11 backend. Necessary?
	FCPPT_ASSERT(
		_param.size()
	);

	awl::window::instance_ptr const result =
		fcppt::make_shared_ptr<
			awl::backends::quartz::window::original_instance
		>(
			_param
		);

	// This seemingly does some additional initialization stuff I'm not
	// too sure about...
	event_loop();

	return result;
}

void
awl::backends::quartz::system::original_object::event_loop()
{
	NSEvent * event;
	std::queue<
		NSEvent *
	> event_queue;
	NSAutoreleasePool * pool =
		[[NSAutoreleasePool alloc] init];
	do
	{
		event =
			[NSApp nextEventMatchingMask: NSAnyEventMask
				untilDate: [NSDate distantPast]
				inMode: NSDefaultRunLoopMode
				dequeue: YES
			];

		if (event)
		{
			event_queue.push(
				event
			);
		}
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
	}

	[pool drain];
}