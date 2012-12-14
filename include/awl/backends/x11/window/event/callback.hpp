#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_CALLBACK_HPP_INCLUDED

#include <awl/backends/x11/window/event/function.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

typedef std::function<
	awl::backends::x11::window::event::function
> callback;

}
}
}
}
}

#endif
