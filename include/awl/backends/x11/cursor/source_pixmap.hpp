#ifndef AWL_BACKENDS_X11_CURSOR_SOURCE_PIXMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_SOURCE_PIXMAP_HPP_INCLUDED

#include <awl/backends/x11/pixmap/holder_fwd.hpp>
#include <fcppt/strong_typedef.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

FCPPT_MAKE_STRONG_TYPEDEF(
	awl::backends::x11::pixmap::holder const &,
	source_pixmap
);

}
}
}
}

#endif
