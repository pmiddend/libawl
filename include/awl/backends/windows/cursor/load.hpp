#ifndef AWL_BACKENDS_WINDOWS_CURSOR_LOAD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_LOAD_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
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
HCURSOR
load(
	fcppt::char_type const *
);

}
}
}
}

#endif
