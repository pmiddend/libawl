#include <awl/backends/x11/window/atom_count.hpp>
#include <awl/backends/x11/window/atoms.hpp>
#include <awl/backends/x11/window/object_fwd.hpp>
#include <awl/backends/x11/window/set_wm_protocols.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <awl/backends/x11/window/event/wm_protocols.hpp>
#include <fcppt/container/raw_vector_impl.hpp>


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
				static_cast<
					int
				>(
					_atoms.size()
				)
			)
		)
	);
}

awl::backends::x11::window::event::wm_protocols::~wm_protocols()
{
}
