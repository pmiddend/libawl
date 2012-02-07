#include <awl/backends/cocoa/system/object.hpp>
#include <awl/backends/cocoa/window/instance.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/cref.hpp>
#import <Cocoa/Cocoa.h>

awl::backends::cocoa::system::object::object()
:
	app_(
			[NSApplication sharedApplication])
{
}

awl::window::instance_unique_ptr
awl::backends::cocoa::system::object::create(
	awl::window::parameters const &_params)
{
	return
		awl::window::instance_unique_ptr(
			fcppt::make_unique_ptr<backends::cocoa::window::instance>(
				fcppt::cref(
					_params)));
}

awl::backends::cocoa::system::object::~object()
{
}
