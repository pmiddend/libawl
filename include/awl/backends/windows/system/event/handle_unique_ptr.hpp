#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_HANDLE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/windows/system/event/handle_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
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

typedef std::unique_ptr<
	awl::backends::windows::system::event::handle
> handle_unique_ptr;

}
}
}
}
}

#endif
