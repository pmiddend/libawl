#ifndef AWL_SYSTEM_EVENT_PROCESSOR_PTR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_PTR_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
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

#endif
