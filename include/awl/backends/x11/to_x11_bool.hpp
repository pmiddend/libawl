#ifndef AWL_BACKENDS_X11_TO_X11_BOOL_HPP_INCLUDED
#define AWL_BACKENDS_X11_TO_X11_BOOL_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

Bool
to_x11_bool(
	bool
);

}
}
}

#endif
