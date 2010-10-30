#include "glx/create_visual_attributes.hpp"
#include "glx/create_visual.hpp"
#include <awl/backends/x11/window_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/backends/x11/event.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/to_std_string.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window_instance::window_instance(
	display_ptr const _display,
	awl::window::parameters const &_params
)
:
	display_(
		_display),
	screen_(
		// In sge, this is wrapped in a function, I don't quite know why
		XDefaultScreen(
			display_->get())),
	visual_(
		_params.has_opengl()
		?
			glx::create_visual(
				display_,
				screen_,
				glx::create_visual_attributes(
					_params.bit_depth(),
					_params.depth_buffer(),
					_params.stencil_buffer()).data())
		:
			fcppt::make_shared_ptr<
				x11::visual
			>(
				display_->get(),
				XDefaultVisual(
					display_->get(),
					screen_))),
	colormap_(
		fcppt::make_shared_ptr<
			x11::colormap
		>(
			display_,
			screen_,
			visual_)),
	wm_hints_(),
	size_hints_(
		_params.size()->w(),
		_params.size()->h(),
		_params.size()->w(),
		_params.size()->h()),
	class_hint_(
		_params.title(),
		_params.class_name())
{
	XSetWindowAttributes swa;
	swa.colormap = colormap_->get();
	swa.border_pixel = 0;
	swa.background_pixel = 0;
	swa.override_redirect = _params.fullscreen() ? True : False;
	swa.event_mask = StructureNotifyMask;

	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_ << FCPPT_TEXT("Creating the x11 window now"))

	// always returns a handle
	window_ = XCreateWindow(
		display_->get(),
		XRootWindow(
			display_->get(),
			screen_),
		static_cast<int>(
			_params.position()->x()),
		static_cast<int>(
			_params.position()->y()),
		static_cast<unsigned>(
			_params.size()->w()),
		static_cast<unsigned>(
			_params.size()->h()),
		// border_width
		0,
		visual_->info()->depth,
		InputOutput,
		visual_->get(),
		CWColormap | CWOverrideRedirect | CWBorderPixel | CWEventMask,
		const_cast<XSetWindowAttributes *>(&swa));

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

void
awl::backends::x11::window_instance::show()
{
	// always returns 1
	::XMapWindow(
		display_->get(),
		window_
	);

	// TODO: what can this return?
	::XSync(
		display_->get(),
		False
	);
}

awl::backends::x11::window_instance::~window_instance()
{
	::XDestroyWindow(
		display_->get(),
		window_
	);
}

awl::backends::x11::display_ptr const
awl::backends::x11::window_instance::display() const
{
	return display_;
}

awl::backends::x11::visual_ptr const
awl::backends::x11::window_instance::visual() const
{
	return visual_;
}

Window
awl::backends::x11::window_instance::get() const
{
	return window_;
}

awl::backends::x11::optional_event const
awl::backends::x11::window_instance::next_event()
{
	XEvent ret;

	return
		::XNextEvent(
			display_->get(),
			&ret
		)
		!= 0
		?
			optional_event(
				x11::event(
					ret
				)
			)
		:
			optional_event();
}

awl::backends::x11::optional_event const
awl::backends::x11::window_instance::peek_event()
{
	XEvent ret;

	return
		::XPeekEvent(
			display_->get(),
			&ret
		)
		!= 0
		?
			optional_event(
				x11::event(
					ret
				)
			)
		:
			optional_event();
}
