#include <awl/backends/x11/asio/fd_flags_resetter.hpp>
#include <awl/backends/x11/asio/get_fd_flags.hpp>
#include <awl/backends/x11/asio/set_fd_flags.hpp>
#include <awl/backends/x11/display_fd.hpp>

awl::backends::x11::asio::fd_flags_resetter::fd_flags_resetter(
	x11::display &_display
)
:
	display_(_display),
	flags_(
		x11::asio::get_fd_flags(
			x11::display_fd(
				display_
			)
		)
	)
{
}

awl::backends::x11::asio::fd_flags_resetter::~fd_flags_resetter()
{
	x11::asio::set_fd_flags(
		x11::display_fd(
			display_
		),
		flags_
	);
}
