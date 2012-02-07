#ifndef AWL_BACKENDS_COCOA_WINDOW_EVENT_AWLWINDOWDELEGATE_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_WINDOW_EVENT_AWLWINDOWDELEGATE_HPP_INCLUDED

#include <awl/backends/cocoa/window/event/processor_fwd.hpp>
#import <Cocoa/Cocoa.h>

@interface AWLWindowDelegate : NSObject<NSWindowDelegate>

- (AWLWindowDelegate *)init: (awl::backends::cocoa::window::event::processor *)parentProcessor;

@end 

#endif
