#include <awl/backends/x11/log.hpp>
#include <awl/log.hpp>
#include <fcppt/text.hpp>

fcppt::log::object &
awl::backends::x11::log()
{
	static fcppt::log::object l(
		fcppt::log::parameters::inherited(
			awl::log(),
			FCPPT_TEXT("x11")));
	return l;
}
