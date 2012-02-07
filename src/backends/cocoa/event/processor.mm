#include <awl/backends/cocoa/event/processor.hpp>
#include <awl/backends/cocoa/window/instance.hpp>
#include <awl/window/event/processor.hpp>
#include <fcppt/algorithm/ptr_container_erase.hpp>
#include <fcppt/optional_impl.hpp>
#import <Cocoa/Cocoa.h>

awl::backends::cocoa::event::processor::processor(
	cocoa::system::object &_system,
	cocoa::system::event::optional_processor_ref const &_optional_processor)
:
	system_(
		_system),
	optional_processor_(
		_optional_processor),
	window_event_processors_()
{
}

awl::backends::cocoa::event::processor::~processor()
{
}

bool
awl::backends::cocoa::event::processor::poll()
{
	NSMutableArray *eventArray = [NSMutableArray arrayWithCapacity:1];

	bool got_an_event =
		false;

	NSApplication *app = [NSApplication sharedApplication];

	NSLog(@"Beginning to poll window");
	while(
		NSEvent *event = 
			[app
				nextEventMatchingMask:NSAnyEventMask
				untilDate:[NSDate distantPast]
				inMode:NSDefaultRunLoopMode
				dequeue:YES])
	{
		NSLog(@"Awww yeah, got an event");
		NSWindow *eventWindow = [event window];

		if(!eventWindow)
		{
			if(!optional_processor_.has_value())
			{
				[eventArray addObject:event];
			}
			else
			{
				got_an_event = true;
				[app sendEvent:event];
				[app updateWindows];
			}
		}
		else
		{
			bool one_of_our_windows = false;
			for(
				window_event_processors::iterator current_window_processor = 
					window_event_processors_.begin();
				current_window_processor != window_event_processors_.end();
				++current_window_processor)
				if(dynamic_cast<backends::cocoa::window::instance &>(current_window_processor->window()).window_ == eventWindow)
					one_of_our_windows = true;

			if(!one_of_our_windows)
			{
				[eventArray addObject:event];
			}
			else
			{
				[app sendEvent:event];
				[app updateWindows];
				got_an_event = true;
			}
		}
	}

	for(NSEvent *e in eventArray)
		[app postEvent:e atStart:TRUE];

	return
		got_an_event;
}

void
awl::backends::cocoa::event::processor::next()
{
	NSMutableArray *eventArray = [NSMutableArray arrayWithCapacity:1];

	NSApplication *app = [NSApplication sharedApplication];

	NSLog(@"Beginning to poll window");
	while(
		NSEvent *event = 
			[app
				nextEventMatchingMask:NSAnyEventMask
				untilDate:[NSDate distantFuture]
				inMode:NSDefaultRunLoopMode
				dequeue:YES])
	{
		NSLog(@"Awww yeah, got an event");
		NSWindow *eventWindow = [event window];

		if(!eventWindow)
		{
			if(!optional_processor_.has_value())
			{
				[eventArray addObject:event];
			}
			else
			{
				[app sendEvent:event];
				[app updateWindows];
				break;
			}
		}
		else
		{
			bool one_of_our_windows = false;
			for(
				window_event_processors::iterator current_window_processor = 
					window_event_processors_.begin();
				current_window_processor != window_event_processors_.end();
				++current_window_processor)
				if(dynamic_cast<backends::cocoa::window::instance &>(current_window_processor->window()).window_ == eventWindow)
					one_of_our_windows = true;

			if(!one_of_our_windows)
			{
				[eventArray addObject:event];
			}
			else
			{
				[app sendEvent:event];
				[app updateWindows];
				break;
			}
		}
	}

	for(NSEvent *e in eventArray)
		[app postEvent:e atStart:TRUE];
}

void
awl::backends::cocoa::event::processor::attach(
	awl::window::event::processor &_processor)
{
	window_event_processors_.push_back(
		&_processor);
}

void
awl::backends::cocoa::event::processor::detach(
	awl::window::event::processor &_processor)
{
	fcppt::algorithm::ptr_container_erase(
		window_event_processors_,
		&_processor);
}
