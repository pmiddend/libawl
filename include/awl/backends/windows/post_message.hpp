#ifndef AWL_BACKENDS_WINDOWS_POST_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_POST_MESSAGE_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>


namespace awl
{
namespace backends
{
namespace windows
{

AWL_SYMBOL
void
post_message(
	HWND,
	UINT,
	WPARAM,
	LPARAM
);

}
}
}

#endif
