#include "create_visual.hpp"
#include <awl/backends/x11/log.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/exception.hpp>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::visual_ptr const
awl::backends::x11::glx::create_visual(
	display_ptr const dsp,
	int screen,
	int const *param)
{
	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_ << FCPPT_TEXT("Creating a glx visual"));	

	XVisualInfo *const info(
		glXChooseVisual(
			dsp->get(),
			screen,
			const_cast<int *>(
				param)));

	if(!info)
		throw exception(
			FCPPT_TEXT("glXChooseVisual() failed!"));

	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_ << FCPPT_TEXT("Got a visual info from glXChooseVisual"));

	return 
		fcppt::make_shared_ptr<visual>(
			dsp->get(),
			info->visual,
			info);
}
