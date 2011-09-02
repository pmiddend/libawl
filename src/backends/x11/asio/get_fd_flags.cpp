#include <awl/backends/x11/asio/get_fd_flags.hpp>
#include <awl/backends/x11/asio/fcntl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <unistd.h>
#include <fcntl.h>
#include <fcppt/config/external_end.hpp>

int
awl::backends::x11::asio::get_fd_flags(
	int const _fd
)
{
	return
		x11::asio::fcntl(
			_fd,
			F_GETFL,
			0
		);
}
