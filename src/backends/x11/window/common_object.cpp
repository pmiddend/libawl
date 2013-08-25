#include <awl/exception.hpp>
#include <awl/backends/x11/discard.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/common_object.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/wrapped_class_hint.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <fcppt/text.hpp>
#include <fcppt/try_dynamic_cast.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::common_object::common_object()
:
	awl::backends::x11::window::object()
{
}

awl::backends::x11::window::common_object::~common_object()
{
}

void
awl::backends::x11::window::common_object::show()
{
	// always returns 1
	::XMapWindow(
		this->display().get(),
		this->get()
	);

	this->display().sync(
		awl::backends::x11::discard(
			false
		)
	);
}

awl::window::dim const
awl::backends::x11::window::common_object::size() const
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
			display().get(),
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
			width_return,
			height_return
		);
}

bool
awl::backends::x11::window::common_object::equal_to(
	awl::window::object const &_other
) const
{
	FCPPT_TRY_DYNAMIC_CAST(
		awl::backends::x11::window::object const *,
		casted_other,
		&_other
	)
	{
		return
			casted_other->get()
			==
			this->get();
	}

	return false;
}
