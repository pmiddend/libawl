#ifndef AWL_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/window/event/processor_fwd.hpp>
#include <fcppt/unique_ptr.hpp>

namespace awl
{
namespace window
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
