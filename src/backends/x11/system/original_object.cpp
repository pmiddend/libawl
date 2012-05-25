#include <awl/backends/x11/default_screen.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/get_input_focus.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/system/original_object.hpp>
#include <awl/backends/x11/visual/default.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/parameters.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/assert/pre.hpp>


awl::backends::x11::system::original_object::original_object()
:
	display_(),
	screen_(
		awl::backends::x11::default_screen(
			display_
		)
	)
{
}

awl::backends::x11::system::original_object::~original_object()
{
}

awl::window::object_unique_ptr
awl::backends::x11::system::original_object::create_window(
	awl::window::parameters const &_param
)
{
	FCPPT_ASSERT_PRE(
		_param.size()
	);

	return
		awl::window::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::x11::window::original_object
			>(
				fcppt::ref(
					display_
				),
				screen_,
				_param
			)
		);
}

awl::visual::object_unique_ptr
awl::backends::x11::system::original_object::default_visual()
{
	return
		awl::visual::object_unique_ptr(
			awl::backends::x11::visual::default_(
				display_,
				screen_
			)
		);
}

awl::window::object_unique_ptr
awl::backends::x11::system::original_object::focus_window()
{
	return
		awl::window::object_unique_ptr(
			awl::backends::x11::get_input_focus(
				display_,
				screen_
			)
		);
}

awl::backends::x11::display &
awl::backends::x11::system::original_object::display()
{
	return display_;
}

awl::backends::x11::screen const
awl::backends::x11::system::original_object::screen() const
{
	return screen_;
}
