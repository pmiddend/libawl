#include <awl/exception.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/window/atoms.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/set_wm_protocols.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::window::set_wm_protocols(
	awl::backends::x11::window::instance const &_instance,
	awl::backends::x11::window::atoms const &_atoms
)
{
	if(
		::XSetWMProtocols(
			_instance.display().get(),
			_instance.get(),
			const_cast<
				Atom *
			>(
				_atoms.get()
			),
			_atoms.count().get()
		)
		==
		0
	)
		throw awl::exception(
			FCPPT_TEXT("XSetWMProtocols failed!")
		);
}
