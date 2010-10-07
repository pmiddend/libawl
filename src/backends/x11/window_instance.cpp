#include "glx/create_visual_attributes.hpp"
#include "glx/create_visual.hpp"
#include <awl/backends/x11/window_instance.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/window/parameters.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/to_std_string.hpp>
#include <X11/Xlib.h>

awl::backends::x11::window_instance::window_instance(
	display_ptr const _display,
	awl::window::parameters const &params)
:
	display_(
		_display),
	screen_(
		// In sge, this is wrapped in a function, I don't quite know why
		XDefaultScreen(
			display_->get())),
	visual_(
		params.has_opengl()
		?
			glx::create_visual(
				display_,
				screen_,
				glx::create_visual_attributes(
					params.bit_depth(),
					params.depth_buffer(),
					params.stencil_buffer()).data())
		:
			fcppt::make_shared_ptr<visual>(
				display_->get(),
				XDefaultVisual(
					display_->get(),
					screen_))),
	colormap_(
		fcppt::make_shared_ptr<colormap>(
			display_,
			screen_,
			visual_)),
	wm_hints_(),
	size_hints_(
		params.size()->w(),
		params.size()->h(),
		params.size()->w(),
		params.size()->h()),
	class_hint_(
		params.title(),
		params.class_name())
{
	XSetWindowAttributes swa;
	swa.colormap = colormap_->get();
	swa.border_pixel = 0;
	swa.background_pixel = 0;
	swa.override_redirect = params.fullscreen() ? True : False;
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
			params.position()->x()),
		static_cast<int>(
			params.position()->y()),
		static_cast<unsigned>(
			params.size()->w()),
		static_cast<unsigned>(
			params.size()->h()),
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
	XSetWMHints(
		display_->get(),
		window_,
		wm_hints_.get());

	// always returns 1
	XSetWMNormalHints(
		display_->get(),
		window_,
		size_hints_.get());

	// always returns 1
	XSetClassHint(
		display_->get(),
		window_,
		class_hint_.get()
	);

	XStoreName(
		display_->get(),
		window_,
		fcppt::to_std_string(
			params.title()).c_str());
}

void
awl::backends::x11::window_instance::show()
{
	// always returns 1
	XMapWindow(
		display_->get(),
		window_);
	XSync(
		display_->get(),
		False);
}

awl::backends::x11::window_instance::~window_instance()
{
	XDestroyWindow(
		display_->get(),
		window_);
}
