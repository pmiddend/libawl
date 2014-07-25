#ifndef AWL_BACKENDS_X11_PIXMAP_CREATE_FROM_DATA_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_CREATE_FROM_DATA_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/pixmap/dim_fwd.hpp>
#include <awl/backends/x11/pixmap/holder_unique_ptr.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace pixmap
{

AWL_SYMBOL
awl::backends::x11::pixmap::holder_unique_ptr
create_from_data(
	awl::backends::x11::window::object const &,
	awl::backends::x11::pixmap::dim,
	char const *
);

}
}
}
}

#endif
