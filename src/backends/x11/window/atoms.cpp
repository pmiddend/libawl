#include <awl/backends/x11/window/atom_count.hpp>
#include <awl/backends/x11/window/atoms.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::window::atoms::atoms(
	Atom const *const _atoms,
	awl::backends::x11::window::atom_count const _count
)
:
	atoms_(
		_atoms
	),
	count_(
		_count
	)
{
}

Atom const *
awl::backends::x11::window::atoms::get() const
{
	return atoms_;
}

awl::backends::x11::window::atom_count const
awl::backends::x11::window::atoms::count() const
{
	return count_;
}
