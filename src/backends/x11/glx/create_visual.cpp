#include "create_visual.hpp"
#include <awl/backends/x11/log.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/exception.hpp>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/text.hpp>

awl::backends::x11::visual_unique_ptr
awl::backends::x11::glx::create_visual(
	x11::display &_display,
	x11::screen const _screen,
	int const *_param
)
{
	FCPPT_LOG_DEBUG(
		log(),
		fcppt::log::_
			<< FCPPT_TEXT("Creating a glx visual")
	);

	XVisualInfo *const info(
		::glXChooseVisual(
			_display.get(),
			_screen.get(),
			const_cast<
				int *
			>(
				_param
			)
		)
	);

	if(
		!info
	)
		throw awl::exception(
			FCPPT_TEXT("glXChooseVisual() failed!")
		);

	FCPPT_LOG_DEBUG(
		x11::log(),
		fcppt::log::_
			<< FCPPT_TEXT("Got a visual info from glXChooseVisual")
	);

	return 
		fcppt::make_unique_ptr<
			x11::visual
		>(
			std::tr1::ref(
				_display
			),
			info->visual,
			info
		);
}
