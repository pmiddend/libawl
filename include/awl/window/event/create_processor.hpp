#ifndef AWL_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/event/processor_unique_ptr.hpp>


namespace awl
{
namespace window
{
namespace event
{

AWL_SYMBOL
event::processor_unique_ptr
create_processor(
	awl::window::object &
);

}
}
}

#endif
