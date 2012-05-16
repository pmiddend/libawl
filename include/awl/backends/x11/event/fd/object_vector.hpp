#ifndef AWL_BACKENDS_X11_EVENT_FD_OBJECT_VECTOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_FD_OBJECT_VECTOR_HPP_INCLUDED

#include <awl/backends/x11/event/fd/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


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

typedef std::vector<
	awl::backends::x11::event::fd::object
> object_vector;

}
}
}
}
}

#endif
