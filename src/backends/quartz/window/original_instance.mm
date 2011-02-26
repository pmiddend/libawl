#include <awl/backends/quartz/window/original_instance.hpp>
#include <awl/window/parameters.hpp>
#import <Cocoa/Cocoa.h>

awl::backends::quartz::window::original_instance::original_instance(
	awl::window::parameters const &_param
)
:
	window_(
		[[NSWindow alloc] initWithContentRect:
				NSMakeRect(
					_param.position()
					?
						_param.position()->x()
					:
						0.0f,
					_param.position()
					?
						_param.position()->y()
					:
						0.0f,
					_param.size()->w(),
					_param.size()->h()
				)
			styleMask:
				NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask | NSMiniaturizableWindowMask
			backing:NSBackingStoreBuffered
			defer:NO]
	)
{
	NSWindow * const window = (NSWindow *) window;
	[window setTitle:
		[NSString stringWithUTF8String:
			_param
				.title().
					c_str()
		]
	];

	if(
		_param.has_opengl()
	)
	{
		
	}

	// This seemingly does some additional initialization stuff I'm not
	// too sure about...
	[NSApp nextEventMatchingMask: NSAnyEventMask
		untilDate:
			[NSDate distantPast]
		inMode: NSDefaultRunLoopMode
		dequeue: YES];
	// TODO Buffer event
}

awl::backends::quartz::window::original_instance::~original_instance()
{
	[(NSWindow *) window_ release];
}

awl::window::dim const
awl::backends::quartz::window::original_instance::size() const
{
	NSSize const dimensions = [(NSWindow *) window_ frame].size;
	return
		awl::window::dim(
			static_cast<int>(
				dimensions.width
			),
			static_cast<int>(
				dimensions.height
			)
		);
}

void
awl::backends::quartz::window::original_instance::show()
{
	[(NSWindow *) window_ makeKeyAndOrderFront:NSApp];
}

awl::backends::quartz::window_ref
awl::backends::quartz::window::original_instance::get() const
{
	return window_;
}
