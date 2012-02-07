#include <awl/backends/cocoa/window/event/AWLWindowDelegate.hpp>
#include <awl/backends/cocoa/window/event/processor.hpp>

@implementation AWLWindowDelegate
{
	@private
	awl::backends::cocoa::window::event::processor *processor_;
}

- (void)windowDidResize:(NSNotification *)notification
{
	processor_->resize();
}

- (void)windowWillClose:(NSNotification *)notification
{
	processor_->destroy();
}

- (AWLWindowDelegate *)init: (awl::backends::cocoa::window::event::processor *)parentProcessor
{
	if(self = [super init])
	{
		processor_ = parentProcessor;
	}

	return self;
}

@end
