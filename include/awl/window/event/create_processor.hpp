#ifndef AWL_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_CREATE_PROCESSOR_HPP_INCLUDED

#include <awl/window/event/processor_ptr.hpp>
#include <awl/window/instance_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace window
{
namespace event
{

AWL_SYMBOL
event::processor_ptr const
create_processor(
	awl::window::instance_ptr
);

}
}
}

#endif
