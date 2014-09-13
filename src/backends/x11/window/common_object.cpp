#include <awl/exception.hpp>
#include <awl/backends/x11/discard.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/common_object.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/backends/x11/window/wrapped_class_hint.hpp>
#include <awl/window/dim.hpp>
#include <awl/window/object.hpp>
#include <awl/window/rect.hpp>
#include <fcppt/maybe.hpp>
#include <fcppt/text.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/cast/try_dynamic.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
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

awl::window::rect const
awl::backends::x11::window::common_object::rect() const
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
		awl::window::rect(
			awl::window::rect::vector(
				x_return,
				y_return
			),
			awl::window::rect::dim(
				fcppt::cast::to_signed(
					width_return
				),
				fcppt::cast::to_signed(
					height_return
				)
			)
		);
}

awl::window::dim const
awl::backends::x11::window::common_object::size() const
{
	return
		fcppt::math::dim::structure_cast<
			awl::window::dim
		>(
			this->rect().size()
		);
}

bool
awl::backends::x11::window::common_object::equal_to(
	awl::window::object const &_other
) const
{
	return
		fcppt::maybe(
			fcppt::cast::try_dynamic<
				awl::backends::x11::window::object const &
			>(
				_other
			),
			[]
			{
				return
					false;
			},
			[
				this
			](
				awl::backends::x11::window::object const &_casted_other
			)
			{
				return
					_casted_other.get()
					==
					this->get();
			}
		);
}
