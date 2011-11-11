#ifndef AWL_BACKENDS_X11_CREATE_VISUAL_INFO_HPP_INCLUDED
#define AWL_BACKENDS_X11_CREATE_VISUAL_INFO_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/visual_info_unique_ptr.hpp>
#include <awl/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

AWL_SYMBOL
x11::visual_info_unique_ptr
create_visual_info(
	x11::display &,
	Visual &
);

}
}
}

#endif
