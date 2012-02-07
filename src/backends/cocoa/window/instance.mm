#include <awl/backends/cocoa/window/instance.hpp>
#include <awl/backends/cocoa/from_fcppt_string.hpp>
#include <awl/window/parameters.hpp>
#import <Cocoa/Cocoa.h>

#include <iostream>

namespace
{
NSUInteger base_style_mask = 
	NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask;
}

awl::backends::cocoa::window::instance::instance(
	awl::window::parameters const &_params)
{
	awl::window::vector const position =
		_params.position()
		?
			*_params.position()
		:
			awl::window::vector::null();

	awl::window::dim const size =
		_params.size()
		?
			*_params.size()
		:
			_params.exact_size_hint()
			?
				*_params.exact_size_hint()
			:
				awl::window::dim::null();

	NSRect frame = 
			NSMakeRect(
				static_cast<float>(
					position.x()),
				static_cast<float>(
					position.y()),
				static_cast<float>(
					size.w()),
				static_cast<float>(
					size.h()));

	window_ = 
		[[NSWindow alloc] initWithContentRect:frame 
			styleMask: base_style_mask
			backing:NSBackingStoreBuffered 
			defer:NO];

	[window_ setTitle: cocoa::from_fcppt_string(_params.title())];

	std::cout << "Title: " << _params.title() << "\n";
	NSLog(@"Created a window with title %@",[window_ title]);

	if(_params.minimum_size_hint())
		[window_
			setContentMinSize:
				NSMakeSize(
					static_cast<float>(
						_params.minimum_size_hint()->w()),
					static_cast<float>(
						_params.minimum_size_hint()->h()))];

	if(_params.maximum_size_hint())
		[window_
			setContentMaxSize:
				NSMakeSize(
					static_cast<float>(
						_params.maximum_size_hint()->w()),
					static_cast<float>(
						_params.maximum_size_hint()->h()))];
}

void
awl::backends::cocoa::window::instance::show()
{
	[window_ makeKeyAndOrderFront:NSApp];
}

awl::window::dim const
awl::backends::cocoa::window::instance::size() const
{
	NSRect frame = [window_ contentRectForFrameRect:[window_ frame]];

	return
		awl::window::dim(
			static_cast<awl::window::dim::value_type>(
				frame.size.width),
			static_cast<awl::window::dim::value_type>(
				frame.size.height));
}

awl::backends::cocoa::window::instance::~instance()
{
}
