#include <awl/backends/x11/window_system.hpp>
#include <awl/backends/x11/window_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::x11::window_system::window_system()
:
	display_(
		fcppt::make_shared_ptr<display>()
	)
{
}

awl::backends::x11::window_system::~window_system()
{
}

awl::window::instance_ptr const
awl::backends::x11::window_system::create(
	awl::window::parameters const &_param
)
{
	FCPPT_ASSERT(
		_param.size()
	);

	return 
		fcppt::make_shared_ptr<
			x11::window_instance
		>(
			display_,
			_param
		);
}
