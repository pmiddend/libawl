#include <awl/backends/windows/window/event/combine_result.hpp>
#include <fcppt/optional_impl.hpp>

awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::combine_result(
	event::return_type const &_a,
	event::return_type const &_b
)
{
	return
		_a
		?
			_a
		:
			_b;
}
