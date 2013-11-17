#ifndef AWL_SYSTEM_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/system/event/processor_unique_ptr.hpp>


namespace awl
{
namespace system
{
namespace event
{

AWL_SYMBOL
event::processor_unique_ptr
create_processor(
	awl::system::object &
);

}
}
}

#endif
