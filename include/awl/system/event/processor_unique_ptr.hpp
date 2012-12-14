#ifndef AWL_SYSTEM_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/system/event/processor_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace system
{
namespace event
{

typedef std::unique_ptr<
	awl::system::event::processor
> processor_unique_ptr;

}
}
}

#endif
