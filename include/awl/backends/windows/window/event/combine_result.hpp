#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_COMBINE_RESULT_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_COMBINE_RESULT_HPP_INCLUDED

#include <awl/backends/windows/window/event/return_type.hpp>

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

event::return_type const
combine_result(
	event::return_type const &,
	event::return_type const &
);

}
}
}
}
}

#endif
