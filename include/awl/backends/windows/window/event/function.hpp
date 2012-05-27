#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_FUNCTION_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_FUNCTION_HPP_INCLUDED

#include <awl/backends/windows/window/event/object_fwd.hpp>
#include <awl/backends/windows/window/event/return_type_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{
namespace event
{

typedef
awl::backends::windows::window::event::return_type
function(
	awl::backends::windows::window::event::object const &
);

}
}
}
}
}

#endif
