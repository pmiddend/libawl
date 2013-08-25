#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_ATOM_VECTOR_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_ATOM_VECTOR_FWD_HPP_INCLUDED

#include <fcppt/container/raw_vector_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
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

typedef fcppt::container::raw_vector<
	Atom
> atom_vector;

}
}
}
}
}

#endif
