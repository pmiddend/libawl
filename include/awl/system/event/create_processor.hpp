#ifndef AWL_SYSTEM_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/system/event/processor_ptr.hpp>
#include <awl/system/object_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace system
{
namespace event
{

AWL_SYMBOL
event::processor_ptr const
create_processor(
	awl::system::object_ptr
);

}
}
}

#endif
