#include <awl/backends/x11/asio/fcntl.hpp>
#include <awl/backends/x11/asio/set_fd_flags.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fcntl.h>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


void
awl::backends::x11::asio::set_fd_flags(
	int const _fd,
	int const _flags
)
{
	x11::asio::fcntl(
		_fd,
		F_SETFL,
		_flags
	);
}
