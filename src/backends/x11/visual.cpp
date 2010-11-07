#include <awl/backends/x11/visual.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/exception.hpp>
#include <fcppt/assert.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

awl::backends::x11::visual::visual(
	Display *const display,
	Visual * const _ptr,
	XVisualInfo *const _info
)
:
	ptr_(
		_ptr),
	info_(
		_info)
{
	FCPPT_ASSERT(ptr_);

	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_ << FCPPT_TEXT("Constructing a visual..."));

	// See http://www.tigr.net/afterstep/X/xlib/utilities/visual.html#XVisualInfo
	if (info_)
	{
		FCPPT_LOG_DEBUG(
			log(),
			fcppt::log::_ << FCPPT_TEXT("Info structure was given..."));
	}
	else
	{
		FCPPT_LOG_DEBUG(
			log(),
			fcppt::log::_ << FCPPT_TEXT("No info was given, trying to guess one..."));

		XVisualInfo tpl;
		// We could do this, but it's ignored by the XGetVisualInfo
		// function...
		//tpl.visual  = ptr_;
		// ...so we take the id
		tpl.visualid = 
			XVisualIDFromVisual(
				ptr_);
		tpl.red_mask =  ptr_->red_mask;
		tpl.green_mask =  ptr_->green_mask;
		tpl.blue_mask =  ptr_->blue_mask;
		tpl.bits_per_rgb =  ptr_->bits_per_rgb;
		tpl.c_class =  ptr_->c_class;
		// Try this if selection doesn't work yet
		// tpl.colormap_size = ptr_->map_entries;

		int number_of_items;

		info_ = 
			XGetVisualInfo(
				display,
				VisualIDMask | 
					VisualRedMaskMask | 
					VisualGreenMaskMask | 
					VisualBlueMaskMask |
					VisualBitsPerRGBMask |
					VisualClassMask /* | VisualColormapSizeMask */, 
				&tpl,
				&number_of_items);

		if (!info_)
			throw exception(FCPPT_TEXT("Couldn't get XVisualInfo structure for Visual"));

		FCPPT_LOG_DEBUG(
			log(),
			fcppt::log::_ 
				<< FCPPT_TEXT("Found ") 
				<< number_of_items 
				<< FCPPT_TEXT(" matching visual infos"));
	}

	FCPPT_ASSERT(
		info_
	);
}

Visual *
awl::backends::x11::visual::get() const
{
	return ptr_;
}

XVisualInfo *
awl::backends::x11::visual::info() const
{
	return info_;
}

awl::backends::x11::visual::~visual()
{
	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_ << FCPPT_TEXT("Destroying a visual"));

	::XFree(
		info_);
}
