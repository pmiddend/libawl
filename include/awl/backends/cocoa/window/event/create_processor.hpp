#ifndef AWL_BACKENDS_COCOA_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/window/event/processor_unique_ptr.hpp>
#include <awl/window/instance_fwd.hpp>

namespace awl
{
namespace backends
{
namespace cocoa
{
namespace window
{
namespace event
{
awl::window::event::processor_unique_ptr
create_processor(
	awl::window::instance &);
}
}
}
}
}

#endif
