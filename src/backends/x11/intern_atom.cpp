#include <awl/exception.hpp>
#include <awl/backends/x11/atom.hpp>
#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/intern_atom.hpp>
#include <fcppt/text.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <string>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::atom const
awl::backends::x11::intern_atom(
	awl::backends::x11::display &_display,
	std::string const &_name
)
{
	Atom const ret(
		::XInternAtom(
			_display.get(),
			_name.c_str(),
			False // only if exists
		)
	);

	if(
		ret == None
	)
		throw awl::exception(
			FCPPT_TEXT("XInternAtom() failed!")
		);

	return
		awl::backends::x11::atom(
			ret
		);
}
