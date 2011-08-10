#include <awl/backends/x11/default_visual.hpp>
#include <awl/backends/x11/create_visual_info.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/wrapped_visual.hpp>
#include <fcppt/assert.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>

awl::backends::x11::visual_unique_ptr
awl::backends::x11::default_visual(
	x11::display &_display,
	x11::screen const _screen
)
{
	Visual *const visual(
		::XDefaultVisual(
			_display.get(),
			_screen.get()
		)
	);

	FCPPT_ASSERT(
		visual
	);

	return
		x11::visual_unique_ptr(
			fcppt::make_unique_ptr<
				x11::wrapped_visual
			>(
				fcppt::ref(
					*visual
				),
				x11::create_visual_info(
					_display,
					*visual
				)
			)
		);
}
