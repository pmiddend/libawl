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
}

awl::backends::quartz::system::original_object::~original_object()
{
	// Release dangling pointers, basically
	[autorelease_pool_ drain];
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

	return
		fcppt::make_shared_ptr<
			awl::backends::quartz::window::original_instance
		>(
			_param
		);
}
