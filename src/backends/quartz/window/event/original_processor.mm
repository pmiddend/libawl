#include <awl/backends/quartz/window/event/original_processor.hpp>
#include <awl/backends/quartz/window/instance.hpp>
#import <Cocoa/Cocoa.h>

awl::backends::quartz::window::event::original_processor::original_processor(
	quartz::window::instance_ptr const _window
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
	NSEvent * event =
		[NSApp nextEventMatchingMask:NSAnyEventMask
		                   untilDate:[NSDate distantPast]
		                      inMode:NSDefaultRunLoopMode
		                     dequeue:YES];
	if(
		[event window] == window_->get()
	)
	{
		[NSApp sendEvent:event];
	}
	return true;
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

awl::window::instance_ptr const
awl::backends::quartz::window::event::original_processor::window() const
{
	return window_;
}
