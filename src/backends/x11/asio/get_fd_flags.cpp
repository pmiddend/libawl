#include <awl/backends/x11/asio/fcntl.hpp>
#include <awl/backends/x11/asio/get_fd_flags.hpp>
#include <fcppt/config/external_begin.hpp>
#include <fcntl.h>
#include <unistd.h>
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
