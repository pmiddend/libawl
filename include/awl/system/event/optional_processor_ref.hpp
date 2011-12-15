#ifndef AWL_SYSTEM_EVENT_OPTIONAL_PROCESSOR_REF_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_OPTIONAL_PROCESSOR_REF_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace system
{
namespace event
{

typedef fcppt::optional<
	awl::system::event::processor &
> optional_processor_ref;

}
}
}

#endif
