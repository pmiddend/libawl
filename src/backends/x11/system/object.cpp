#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/window/original_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::x11::system::object::object()
:
	display_(
		fcppt::make_shared_ptr<display>()
	)
{
}

awl::backends::x11::system::object::~object()
{
}

awl::window::instance_ptr const
awl::backends::x11::system::object::create(
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
