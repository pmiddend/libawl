#ifndef AWL_BACKENDS_X11_VISUAL_DEFAULT_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_DEFAULT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_unique_ptr.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

AWL_SYMBOL
awl::backends::x11::visual::object_unique_ptr
default_(
	awl::backends::x11::display &,
	awl::backends::x11::screen
);

}
}
}
}

#endif
