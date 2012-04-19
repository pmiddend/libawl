#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/create_info.hpp>
#include <awl/backends/x11/visual/default.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/backends/x11/visual/wrapped.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/assert/post.hpp>


awl::backends::x11::visual::object_unique_ptr
awl::backends::x11::visual::default_(
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen
)
{
	Visual *const visual(
		::XDefaultVisual(
			_display.get(),
			_screen.get()
		)
	);

	FCPPT_ASSERT_POST(
		visual,
		awl::exception
	);

	return
		awl::backends::x11::visual::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::x11::visual::wrapped
			>(
				awl::backends::x11::visual::create_info(
					_display,
					*visual
				)
			)
		);
}
