#include <awl/system/object.hpp>
#include <awl/window/has_focus.hpp>
#include <awl/window/object.hpp>
#include <awl/window/object_unique_ptr.hpp>


bool
awl::window::has_focus(
	awl::system::object &_system,
	awl::window::object const &_window
)
{
	awl::window::object_unique_ptr const focus_window(
		_system.focus_window()
	);

	return
		!focus_window
		?
			false
		:
			_window.equal_to(
				*focus_window
			)
		;
}
