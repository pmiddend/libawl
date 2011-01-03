#include <awl/backends/x11/asio/set_fd_flags.hpp>
#include <awl/backends/x11/asio/fcntl.hpp>
#include <unistd.h>
#include <fcntl.h>

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
