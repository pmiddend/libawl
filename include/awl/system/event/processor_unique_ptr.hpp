#ifndef AWL_SYSTEM_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <fcppt/unique_ptr.hpp>

namespace awl
{
namespace system
{
namespace event
{

typedef fcppt::unique_ptr<
	event::processor
> processor_unique_ptr;

}
}
}

#endif
