#ifndef AWL_BACKENDS_COCOA_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/event/processor_unique_ptr.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/system/event/optional_processor_ref.hpp>

namespace awl
{
namespace backends
{
namespace cocoa
{
namespace event
{
awl::event::processor_unique_ptr
create_processor(
	awl::system::object &,
	awl::system::event::optional_processor_ref const &);
}
}
}
}

#endif
