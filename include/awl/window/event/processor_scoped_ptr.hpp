#ifndef AWL_WINDOW_EVENT_PROCESSOR_SCOPED_PTR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_PROCESSOR_SCOPED_PTR_HPP_INCLUDED

#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace window
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
