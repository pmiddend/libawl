#ifndef AWL_BACKENDS_WINDOWS_EVENT_PEEK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_PEEK_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/optional_message.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

AWL_SYMBOL
awl::backends::windows::event::optional_message const
peek(
	HWND
);

}
}
}
}

#endif
