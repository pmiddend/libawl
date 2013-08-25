#include <awl/backends/x11/window/atom_count.hpp>
#include <awl/backends/x11/window/atoms.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/set_wm_protocols.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <awl/backends/x11/window/event/wm_protocols.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>


awl::backends::x11::window::event::wm_protocols::wm_protocols(
	awl::backends::x11::window::object &_object,
	awl::backends::x11::window::event::atom_vector const &_atoms
)
{
	awl::backends::x11::window::set_wm_protocols(
		_object,
		awl::backends::x11::window::atoms(
			_atoms.data(),
			awl::backends::x11::window::atom_count(
				fcppt::cast::size<
					int
				>(
					fcppt::cast::to_signed(
						_atoms.size()
					)
				)
			)
		)
	);
}

awl::backends::x11::window::event::wm_protocols::~wm_protocols()
{
}
