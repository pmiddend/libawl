#include <awl/backends/cocoa/window/instance.hpp>
#include <awl/backends/cocoa/from_fcppt_string.hpp>
#include <awl/window/parameters.hpp>
#import <Cocoa/Cocoa.h>

#include <iostream>

namespace
{
NSUInteger base_style_mask = 
	NSTitledWindowMask | NSClosableWindowMask | NSResizableWindowMask | NSMiniaturizableWindowMask;
}

awl::backends::cocoa::window::instance::instance(
	awl::window::parameters const &_params)
:
	has_opengl_(
		_params.has_opengl()),
	bit_depth_(
		_params.bit_depth()),
	stencil_buffer_(
		_params.stencil_buffer()),
	depth_buffer_(
		_params.depth_buffer())
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

bool
awl::backends::cocoa::window::instance::has_opengl() const
{
	return has_opengl_;
}

fcppt::optional<awl::window::bit_depth::type> const
awl::backends::cocoa::window::instance::bit_depth() const
{
	return bit_depth_;
}

fcppt::optional<awl::window::stencil_buffer::type> const
awl::backends::cocoa::window::instance::stencil_buffer() const
{
	return stencil_buffer_;
}

fcppt::optional<awl::window::depth_buffer::type> const
awl::backends::cocoa::window::instance::depth_buffer() const
{
	return depth_buffer_;
}

NSWindow *
awl::backends::cocoa::window::instance::window_handle()
{
	return window_;
}

awl::backends::cocoa::window::instance::~instance()
{
}
