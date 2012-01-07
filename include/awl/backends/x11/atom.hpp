#ifndef AWL_BACKENDS_X11_ATOM_HPP_INCLUDED
#define AWL_BACKENDS_X11_ATOM_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

FCPPT_MAKE_STRONG_TYPEDEF(
	Atom,
	atom
);

}
}
}

#endif
