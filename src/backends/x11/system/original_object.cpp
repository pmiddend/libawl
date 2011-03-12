#include <awl/backends/x11/system/original_object.hpp>
#include <awl/backends/x11/window/original_instance.hpp>
#include <awl/backends/x11/original_display.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::x11::system::original_object::original_object()
:
	display_()
{
}

awl::backends::x11::system::original_object::~original_object()
{
}

awl::window::instance_ptr const
awl::backends::x11::system::original_object::create(
	awl::window::parameters const &_param
)
{
	FCPPT_ASSERT(
		_param.size()
	);

	return 
		fcppt::make_shared_ptr<
			x11::window::original_instance
		>(
			display_,
			_param
		);
}

awl::backends::x11::display &
awl::backends::x11::system::original_object::display()
{
	return display_;
}
