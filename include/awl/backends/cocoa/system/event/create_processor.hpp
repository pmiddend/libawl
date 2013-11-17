#ifndef AWL_BACKENDS_COCOA_SYSTEM_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_SYSTEM_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <awl/system/event/processor_unique_ptr.hpp>


namespace awl
{
namespace backends
{
namespace cocoa
{
namespace system
{
namespace event
{
awl::system::event::processor_unique_ptr
create_processor(
	awl::system::object &);
}
}
}
}
}

#endif
