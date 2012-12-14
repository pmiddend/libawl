#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/windows/window/event/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


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

typedef std::function<
	awl::backends::windows::window::event::function
> callback;

}
}
}
}
}

#endif
