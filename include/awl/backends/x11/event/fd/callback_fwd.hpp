#ifndef AWL_BACKENDS_X11_EVENT_FD_CALLBACK_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_CALLBACK_FWD_HPP_INCLUDED

#include <awl/backends/x11/event/fd/function.hpp>
#include <fcppt/function/object_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace event
{
namespace fd
{

typedef fcppt::function::object<
	awl::backends::x11::event::fd::function
> callback;

}
}
}
}
}

#endif
