#ifndef AWL_BACKENDS_X11_CURSOR_FOREGROUND_COLOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_FOREGROUND_COLOR_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

FCPPT_MAKE_STRONG_TYPEDEF(
	XColor,
	foreground_color
);

}
}
}
}

#endif
