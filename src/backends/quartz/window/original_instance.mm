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
			                        styleMask:NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask | NSMiniaturizableWindowMask
			                          backing:NSBackingStoreBuffered
			                            defer:NO]
	)
{
	[window_ setTitle:
		[NSString stringWithUTF8String:_param.title().c_str()]];

	if(
		_param.has_opengl()
	)
	{
		
	}
}

awl::backends::quartz::window::original_instance::~original_instance()
{
	[window_ release];
}

awl::window::dim const
awl::backends::quartz::window::original_instance::size() const
{
	NSWindow * window = static_cast<NSWindow *>(window_);
	return
		awl::window::dim(
			static_cast<int>(
				[window frame].size.width
			),
			static_cast<int>(
				[window frame].size.height
			)
		);
}

void
awl::backends::quartz::window::original_instance::show()
{
	[window_ makeKeyAndOrderFront:NSApp];
}
