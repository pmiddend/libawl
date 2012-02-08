#include <awl/backends/cocoa/system/create.hpp>
#include <awl/backends/cocoa/system/object.hpp>
#include <fcppt/make_unique_ptr.hpp>

awl::system::object_unique_ptr
awl::backends::cocoa::system::create()
{
	return
		awl::system::object_unique_ptr(
			fcppt::make_unique_ptr<awl::backends::cocoa::system::object>());
}
