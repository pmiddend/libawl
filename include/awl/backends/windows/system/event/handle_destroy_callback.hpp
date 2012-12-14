#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_DESTROY_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_DESTROY_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
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
	void(
		HANDLE
	)
> handle_destroy_callback;

}
}
}
}
}

#endif
