#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_PTR_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

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

typedef fcppt::shared_ptr<
	event::handle
> handle_ptr;

}
}
}
}
}

#endif
