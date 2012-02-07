#include <awl/backends/cocoa/window/event/processor.hpp>
#include <awl/backends/cocoa/window/event/AWLWindowDelegate.hpp>
#include <awl/backends/cocoa/window/instance.hpp>
#include <awl/window/event/destroy.hpp>
#include <awl/window/event/resize.hpp>
#include <fcppt/math/dim/basic_impl.hpp>

awl::backends::cocoa::window::event::processor::processor(
	cocoa::window::instance &_window)
:
	window_(
		_window),
	resize_(),
	destroy_()
{
	delegate_ = [[AWLWindowDelegate alloc] init:this];
	[_window.window_ setDelegate:delegate_];
}

bool
awl::backends::cocoa::window::event::processor::poll()
{
	NSApplication *app = [NSApplication sharedApplication];

	bool got_event = false;

	while(
		NSEvent *event =
			[app
				nextEventMatchingMask:NSAnyEventMask
				untilDate:[NSDate distantPast]
				inMode:NSDefaultRunLoopMode
				dequeue:YES])
	{
		got_event = true;
		[app sendEvent:event];
	}

	return got_event;
}

fcppt::signal::auto_connection
awl::backends::cocoa::window::event::processor::destroy_callback(
	awl::window::event::destroy_callback const &_destroy_callback)
{
	return
		destroy_.connect(
			_destroy_callback);
}

fcppt::signal::auto_connection
awl::backends::cocoa::window::event::processor::resize_callback(
	awl::window::event::resize_callback const &_resize_callback)
{
	return
		resize_.connect(
			_resize_callback);
}

awl::window::instance &
awl::backends::cocoa::window::event::processor::window() const
{
	return window_;
}

void
awl::backends::cocoa::window::event::processor::resize()
{
	resize_(
		awl::window::event::resize(
			window_,
			window_.size()));
}

void
awl::backends::cocoa::window::event::processor::destroy()
{
	destroy_(
		awl::window::event::destroy(
			window_));
}

awl::backends::cocoa::window::event::processor::~processor()
{
}
