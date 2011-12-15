#ifndef AWL_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/event/processor_unique_ptr.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/system/event/optional_processor_ref.hpp>


namespace awl
{
namespace event
{

AWL_SYMBOL
awl::event::processor_unique_ptr
create_processor(
	awl::system::object &,
	awl::system::event::optional_processor_ref const &
);

}
}

#endif
