#include <awl/backends/x11/window/common_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/exception.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/text.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window::common_instance::common_instance()
{
}

awl::backends::x11::window::common_instance::~common_instance()
{
}

void
awl::backends::x11::window::common_instance::show()
{
	// always returns 1
	::XMapWindow(
		display()->get(),
		get()
	);

	// always returns 1
	::XSync(
		display()->get(),
		False
	);
}

awl::window::dim const
awl::backends::x11::window::common_instance::size() const
{
	Window root_return;

	int
		x_return,
		y_return;

	unsigned
		width_return,
		height_return,
		border_width_return,
		depth_return;

	if(
		::XGetGeometry(
			display()->get(),
			get(),
			&root_return,
			&x_return,
			&y_return,
			&width_return,
			&height_return,
			&border_width_return,
			&depth_return
		) == 0
	)
                throw awl::exception(
                        FCPPT_TEXT("XGetGeometry() failed!")
                );

	return
		awl::window::dim(
			static_cast<
				awl::window::dim::value_type
			>(
				width_return
			),
			static_cast<
				awl::window::dim::value_type
			>(
				height_return
			)
		);
}
