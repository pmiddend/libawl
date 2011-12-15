#ifndef AWL_EVENT_PROCESSOR_SCOPED_PTR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_SCOPED_PTR_HPP_INCLUDED

#include <awl/event/processor_fwd.hpp>
#include <fcppt/scoped_ptr.hpp>


namespace awl
{
namespace event
{

typedef fcppt::scoped_ptr<
	awl::event::processor
> processor_scoped_ptr;

}
}

#endif
