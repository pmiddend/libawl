#ifndef AWL_SYSTEM_EVENT_PROCESSOR_SCOPED_PTR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_SCOPED_PTR_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace system
{
namespace event
{

typedef fcppt::scoped_ptr<
	event::processor
> processor_scoped_ptr;

}
}
}

#endif
