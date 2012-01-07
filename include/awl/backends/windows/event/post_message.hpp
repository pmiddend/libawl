#ifndef AWL_BACKENDS_WINDOWS_EVENT_POST_MESSAGE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_EVENT_POST_MESSAGE_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace event
{

AWL_SYMBOL
void
post_message(
	HWND,
	awl::backends::windows::event::type,
	awl::backends::windows::event::wparam,
	awl::backends::windows::event::lparam
);

}
}
}
}

#endif
