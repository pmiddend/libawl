#ifndef AWL_BACKENDS_X11_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CREATE_PREDEFINED_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/cursor/object_unique_ptr.hpp>
#include <awl/cursor/predefined_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

AWL_SYMBOL
awl::backends::x11::cursor::object_unique_ptr
create_predefined(
	awl::backends::x11::display const &,
	awl::cursor::predefined
);

}
}
}
}

#endif
