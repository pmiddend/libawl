#ifndef AWL_EVENT_PROCESSOR_PTR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_PTR_HPP_INCLUDED

#include <awl/event/processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace event
{

typedef fcppt::shared_ptr<
	processor
> processor_ptr;

}
}

#endif
