#ifndef AWL_BACKENDS_X11_WINDOW_ATOMS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ATOMS_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/window/atom_count.hpp>
#include <awl/backends/x11/window/atoms_fwd.hpp>
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

class atoms
{
public:
	AWL_SYMBOL
	atoms(
		Atom const *,
		awl::backends::x11::window::atom_count
	);

	AWL_SYMBOL
	Atom const *
	get() const;

	AWL_SYMBOL
	awl::backends::x11::window::atom_count const
	count() const;
private:
	Atom const *atoms_;

	awl::backends::x11::window::atom_count count_;
};

}
}
}
}

#endif
