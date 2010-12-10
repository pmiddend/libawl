#ifndef AWL_BACKENDS_X11_EVENT_PROCESSOR_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_PROCESSOR_PTR_HPP_INCLUDED

#include <awl/backends/x11/event_processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

typedef fcppt::shared_ptr<
	event_processor
> event_processor_ptr;

}
}
}

#endif
