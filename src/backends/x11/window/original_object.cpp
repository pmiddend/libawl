#include <awl/config.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <awl/backends/x11/window/create.hpp>
#include <awl/backends/x11/window/original_object.hpp>
#include <awl/backends/x11/window/root.hpp>
#include <awl/backends/x11/window/transient_for_hint.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/to_std_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::original_object::original_object(
	awl::backends::x11::display &_display,
	awl::backends::x11::screen const _screen,
	awl::window::parameters const &_params
)
:
	display_(
		_display
	),
	screen_(
		_screen
	),
	visual_(
		dynamic_cast<
			awl::backends::x11::visual::object const &
		>(
			_params.visual()
		)
	),
	colormap_(
		display_,
		_screen,
		visual_
	),
	hints_(),
	size_hints_(
		_params.exact_size_hint(),
		_params.minimum_size_hint(),
		_params.maximum_size_hint()
	),
	class_hint_(
		_params.title(),
		_params.class_name()
	),
	window_(
		display_,
		x11::window::create(
			_params.position(),
			_params.size(),
			display_,
			screen_,
			colormap_,
			visual_
		)
	)
{
	// always returns 1
	::XSetWMHints(
		display_.get(),
		window_.get(),
		hints_.get()
	);

	// always returns 1
	::XSetWMNormalHints(
		display_.get(),
		window_.get(),
		size_hints_.get()
	);

	// always returns 1
	::XSetClassHint(
		display_.get(),
		window_.get(),
		class_hint_.get()
	);

	// always returns 1
	::XStoreName(
		display_.get(),
		window_.get(),
		fcppt::to_std_string(
			_params.title()
		).c_str()
	);

	if(
		_params.exact_size_hint()
	)
		x11::window::transient_for_hint(
			*this,
			*x11::window::root(
				display_,
				screen_
			)
		);
}

awl::backends::x11::window::original_object::~original_object()
{
}

void
awl::backends::x11::window::original_object::destroy()
{
	window_.destroy();
}

bool
awl::backends::x11::window::original_object::destroyed() const
{
	return
		window_.destroyed();
}

awl::backends::x11::display &
awl::backends::x11::window::original_object::display() const
{
	return display_;
}

awl::backends::x11::screen const
awl::backends::x11::window::original_object::screen() const
{
	return screen_;
}

awl::backends::x11::visual::object const &
awl::backends::x11::window::original_object::visual() const
{
	return visual_;
}

Window
awl::backends::x11::window::original_object::get() const
{
	return window_.get();
}

awl::backends::x11::window::class_hint const *
awl::backends::x11::window::original_object::class_hint() const
{
	return &class_hint_;
}
