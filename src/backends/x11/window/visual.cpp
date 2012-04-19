#include <awl/backends/x11/visual/create_info.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>
#include <awl/backends/x11/visual/wrapped.hpp>
#include <awl/backends/x11/window/attributes.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/visual.hpp>
#include <fcppt/make_unique_ptr.hpp>


awl::backends::x11::visual::object_unique_ptr
awl::backends::x11::window::visual(
	awl::backends::x11::window::object &_window
)
{
	return
		awl::backends::x11::visual::object_unique_ptr(
			fcppt::make_unique_ptr<
				awl::backends::x11::visual::wrapped
			>(
				awl::backends::x11::visual::create_info(
					_window.display(),
					*awl::backends::x11::window::attributes(
						_window
					).visual
				)
			)
		);
}
