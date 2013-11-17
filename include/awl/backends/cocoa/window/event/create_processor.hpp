#ifndef AWL_BACKENDS_COCOA_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/window/object_fwd.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>


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
	awl::window::object &);
}
}
}
}
}

#endif
