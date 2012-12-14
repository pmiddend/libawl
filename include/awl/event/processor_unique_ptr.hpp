#ifndef AWL_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_UNIQUE_PTR_HPP_INCLUDED

#include <awl/event/processor_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace event
{

typedef std::unique_ptr<
	awl::event::processor
> processor_unique_ptr;

}
}

#endif
