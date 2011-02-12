#ifndef AWL_BACKENDS_QUARTZ_WINDOW_EVENT_PROCESSOR_PTR_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_WINDOW_EVENT_PROCESSOR_PTR_HPP_INCLUDED

#include <awl/backends/quartz/window/event/processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace window
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
