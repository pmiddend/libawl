#include "../glx/create_visual_attributes.hpp"
#include "../glx/create_visual.hpp"
#include <awl/backends/x11/window/original_instance.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/to_std_string.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window::original_instance::original_instance(
	x11::display_ptr const _display,
	awl::window::parameters const &_params
)
:
	display_(
		_display
	),
	screen_(
		::XDefaultScreen(
			display_->get()
		)
	),
	visual_(
		_params.has_opengl()
		?
			glx::create_visual(
				display_,
				screen_,
				glx::create_visual_attributes(
					_params.bit_depth(),
					_params.depth_buffer(),
					_params.stencil_buffer()
				).data()
			)
		:
			fcppt::make_shared_ptr<
				x11::visual
			>(
				display_->get(),
				::XDefaultVisual(
					display_->get(),
					screen_.get()
				)
			)
	),
	colormap_(
		fcppt::make_shared_ptr<
			x11::colormap
		>(
			display_,
			screen_,
			visual_
		)
	),
	wm_hints_(),
	size_hints_(
		_params.size()->w(),
		_params.size()->h(),
		_params.size()->w(),
		_params.size()->h()
	),
	class_hint_(
		_params.title(),
		_params.class_name()
	)
{
	XSetWindowAttributes swa;
	swa.colormap = colormap_->get();
	swa.border_pixel = 0;
	swa.background_pixel = 0;
	swa.event_mask = StructureNotifyMask;

	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_ << FCPPT_TEXT("Creating the x11 window now"))

	// always returns a handle
	window_ = ::XCreateWindow(
		display_->get(),
		::XRootWindow(
			display_->get(),
			screen_.get()
		),
		_params.position()
		?
			static_cast<int>(
				_params.position()->x()
			)
		:
			0,
		_params.position()
		?
			static_cast<int>(
				_params.position()->y()
			)
		:
			0,
		static_cast<unsigned>(
			_params.size()->w()
		),
		static_cast<unsigned>(
			_params.size()->h()
		),
		// border_width
		0,
		visual_->info()->depth,
		InputOutput,
		visual_->get(),
		CWColormap | CWBorderPixel | CWEventMask,
		const_cast<XSetWindowAttributes *>(&swa)
	);

	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_ << FCPPT_TEXT("Window created"));

	// always returns 1
	::XSetWMHints(
		display_->get(),
		window_,
		wm_hints_.get());

	// always returns 1
	::XSetWMNormalHints(
		display_->get(),
		window_,
		size_hints_.get()
	);

	// always returns 1
	::XSetClassHint(
		display_->get(),
		window_,
		class_hint_.get()
	);

	// TODO: what can this return?
	::XStoreName(
		display_->get(),
		window_,
		fcppt::to_std_string(
			_params.title()
		).c_str()
	);
}

awl::backends::x11::window::original_instance::~original_instance()
{
	::XDestroyWindow(
		display_->get(),
		window_
	);
}

awl::backends::x11::display_ptr const
awl::backends::x11::window::original_instance::display() const
{
	return display_;
}

awl::backends::x11::screen const
awl::backends::x11::window::original_instance::screen() const
{
	return screen_;
}

awl::backends::x11::visual_ptr const
awl::backends::x11::window::original_instance::visual() const
{
	return visual_;
}

Window
awl::backends::x11::window::original_instance::get() const
{
	return window_;
}
