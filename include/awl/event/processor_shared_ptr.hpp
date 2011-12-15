#ifndef AWL_EVENT_PROCESSOR_SHARED_PTR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_SHARED_PTR_HPP_INCLUDED

#include <awl/event/processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>


namespace awl
{
namespace event
{

typedef fcppt::shared_ptr<
	awl::event::processor
> processor_shared_ptr;

}
}

#endif
