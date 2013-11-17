#ifndef AWL_BACKENDS_X11_VISUAL_CREATE_INFO_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_CREATE_INFO_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

AWL_SYMBOL
awl::backends::x11::visual::info_unique_ptr
create_info(
	awl::backends::x11::display &,
	Visual &
);

}
}
}
}

#endif
