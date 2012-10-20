#ifndef AWL_BACKENDS_X11_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/cursor/shape.hpp>
#include <awl/cursor/predefined.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

AWL_SYMBOL
awl::backends::x11::cursor::shape const
convert_predefined(
	awl::cursor::predefined::type
);

}
}
}
}

#endif
