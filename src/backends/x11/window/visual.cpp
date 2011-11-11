#include <awl/backends/x11/create_visual_info.hpp>
#include <awl/backends/x11/wrapped_visual.hpp>
#include <awl/backends/x11/window/attributes.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/visual.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>


awl::backends::x11::visual_unique_ptr
awl::backends::x11::window::visual(
	awl::backends::x11::window::instance &_window
)
{
	Visual &visual(
		*window::attributes(
			_window
		).visual
	);

	return
		x11::visual_unique_ptr(
			fcppt::make_unique_ptr<
				x11::wrapped_visual
			>(
				fcppt::ref(
					visual
				),
				x11::create_visual_info(
					_window.display(),
					visual
				)
			)
		);
}
