#ifndef AWL_BACKENDS_WINDOWS_FORMAT_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_FORMAT_MESSAGE_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/string.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

AWL_SYMBOL
fcppt::string
format_message(
	DWORD
);

}
}
}

#endif
