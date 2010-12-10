#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_PTR_HPP_INCLUDED

#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
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
