#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_OPTIONAL_PROCESSOR_REF_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_OPTIONAL_PROCESSOR_REF_HPP_INCLUDED

#include <awl/backends/windows/system/event/processor_fwd.hpp>
#include <fcppt/optional_fwd.hpp>


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

typedef fcppt::optional<
	awl::backends::windows::system::event::processor &
> optional_processor_ref;

}
}
}
}
}

#endif
