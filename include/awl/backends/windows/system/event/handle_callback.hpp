#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle_function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

typedef std::function<
	awl::backends::windows::system::event::handle_function
> handle_callback;
}
}
}
}
}

#endif
