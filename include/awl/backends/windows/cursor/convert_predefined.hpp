#ifndef AWL_BACKENDS_WINDOWS_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_CONVERT_PREDEFINED_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/cursor/predefined_fwd.hpp>
#include <fcppt/char_type.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

AWL_SYMBOL
fcppt::char_type const *
convert_predefined(
	awl::cursor::predefined
);

}
}
}
}

#endif
