#ifndef AWL_WINDOW_EVENT_PROCESSOR_SHARED_PTR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_PROCESSOR_SHARED_PTR_HPP_INCLUDED

#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/shared_ptr_impl.hpp>

namespace awl
{
namespace window
{
namespace event
{

typedef fcppt::shared_ptr<
	event::processor
> processor_shared_ptr;

}
}
}

#endif
