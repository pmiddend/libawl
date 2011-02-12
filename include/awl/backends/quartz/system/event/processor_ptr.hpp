#ifndef AWL_BACKENDS_QUARTZ_SYSTEM_EVENT_PROCESSOR_PTR_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_SYSTEM_EVENT_PROCESSOR_PTR_HPP_INCLUDED

#include <awl/backends/quartz/system/event/processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace system
{
namespace event
{

typedef fcppt::shared_ptr<
	event::processor
> processor_ptr;

}
}
}
}
}

#endif
