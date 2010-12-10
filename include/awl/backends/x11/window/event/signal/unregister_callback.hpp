#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_UNREGISTER_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_UNREGISTER_CALLBACK_HPP_INCLUDED

#include <fcppt/function/object.hpp>

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
namespace signal
{

typedef fcppt::function::object<
	void ()
> unregister_callback;

}
}
}
}
}
}

#endif
