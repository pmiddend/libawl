#include <awl/backends/windows/window/event/combine_result.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>


awl::backends::windows::window::event::return_type const
awl::backends::windows::window::event::combine_result(
	awl::backends::windows::window::event::return_type const &_a,
	awl::backends::windows::window::event::return_type const &_b
)
{
	return
		_a
		?
			_a
		:
			_b;
}
