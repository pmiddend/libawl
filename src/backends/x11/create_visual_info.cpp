#include <awl/exception.hpp>
#include <awl/backends/x11/create_visual_info.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual_info_unique_ptr.hpp>
#include <fcppt/move.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::visual_info_unique_ptr
awl::backends::x11::create_visual_info(
	x11::display &_display,
	Visual &_visual
)
{
	XVisualInfo tpl;
	// We could do this, but it's ignored by the XGetVisualInfo
	// function...
	//tpl.visual  = ptr_;
	// ...so we take the id
	tpl.visualid =
		::XVisualIDFromVisual(
			&_visual
		);

	tpl.red_mask =  _visual.red_mask;
	tpl.green_mask =  _visual.green_mask;
	tpl.blue_mask =  _visual.blue_mask;
	tpl.bits_per_rgb =  _visual.bits_per_rgb;
	tpl.c_class =  _visual.c_class;

	// Try this if selection doesn't work yet
	// tpl.colormap_size = ptr_->map_entries;

	int number_of_items;

	x11::visual_info_unique_ptr ret(
		::XGetVisualInfo(
			_display.get(),
			VisualIDMask |
			VisualRedMaskMask |
			VisualGreenMaskMask |
			VisualBlueMaskMask |
			VisualBitsPerRGBMask |
			VisualClassMask /* | VisualColormapSizeMask */,
			&tpl,
			&number_of_items
		)
	);

	if(
		!ret
	)
		throw awl::exception(
			FCPPT_TEXT("Couldn't get XVisualInfo structure for Visual")
		);

	return
		fcppt::move(
			ret
		);
}
