#include <awl/backends/quartz/system/original_object.hpp>
#include <awl/backends/quartz/window/original_instance.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/make_shared_ptr.hpp>

#import <Cocoa/Cocoa.h>

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
	fetch_and_buffer_events();
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
	fetch_and_buffer_events();

	return result;
}

void
awl::backends::quartz::system::original_object::fetch_and_buffer_events()
{
	NSEvent * event;
	while ((
		event
		=
		[NSApp nextEventMatchingMask: NSAnyEventMask
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
awl::backends::quartz::system::original_object::dispatch_events_for_window(window_ref const window_or_null)
{
	bool events_dispatched = false;

	event_queue queue = event_buffer_[window_or_null];
	while (
		!queue.empty()
	)
	{
		events_dispatched = true;
		[NSApp sendEvent:(NSEvent *)queue.front()];
		queue.pop();
	}

	return events_dispatched;
}
