#ifndef AWL_BACKENDS_X11_INTERN_ATOM_HPP_INCLUDED
#define AWL_BACKENDS_X11_INTERN_ATOM_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{

AWL_SYMBOL
awl::backends::x11::atom const
intern_atom(
	awl::backends::x11::display &,
	std::string const &
);

}
}
}

#endif
