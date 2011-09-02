#include "create_visual.hpp"
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/log.hpp>
#include <awl/backends/x11/wrapped_visual.hpp>
#include <awl/backends/x11/visual_info_unique_ptr.hpp>
#include <awl/exception.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <GL/glx.h>
#include <fcppt/config/external_end.hpp>

awl::backends::x11::visual_unique_ptr
awl::backends::x11::glx::create_visual(
	x11::display &_display,
	x11::screen const _screen,
	int const *_param
)
{
	FCPPT_LOG_DEBUG(
		x11::log(),
		fcppt::log::_
			<< FCPPT_TEXT("Creating a glx visual")
	);

	x11::visual_info_unique_ptr info(
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

	// FIXME: why does this segfault?
	return
		x11::visual_unique_ptr(
			new x11::wrapped_visual(
//			fcppt::make_unique_ptr<
//				x11::wrapped_visual
//			>(
				fcppt::ref(
					*info->visual
				),
				move(
					info
				)
			)
		);
}
