#include <awl/backends/x11/window/visual.hpp>
#include <awl/backends/x11/window/attributes.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/visual.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>

awl::backends::x11::visual_unique_ptr
awl::backends::x11::window::visual(
	awl::backends::x11::window::instance &_window
)
{
	return
		fcppt::make_unique_ptr<
			x11::visual
		>(
			fcppt::ref(
				_window.display()
			),
			window::attributes(
				_window
			).visual
		);
}
