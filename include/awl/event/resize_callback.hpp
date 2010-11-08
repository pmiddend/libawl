#ifndef AWL_EVENT_RESIZE_CALLBACK_HPP_INCLUDED
#define AWL_EVENT_RESIZE_CALLBACK_HPP_INCLUDED

#include <awl/event/resize_function.hpp>
#include <fcppt/function/object.hpp>

namespace awl
{
namespace event
{

typedef fcppt::function::object<
	event::resize_function
> resize_callback;

}
}

#endif
