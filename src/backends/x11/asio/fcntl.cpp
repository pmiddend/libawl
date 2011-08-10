#include <awl/backends/x11/asio/fcntl.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>
#include <unistd.h>
#include <fcntl.h>

int
awl::backends::x11::asio::fcntl(
	int const _fd,
	int const _cmd,
	int const _flags
)
{
	int const ret(
		::fcntl(
			_fd,
			_cmd,
			_flags
		)
	);

	if(
		ret == -1
	)
		throw awl::exception(
			FCPPT_TEXT("fcntl() failed!")
		);

	return ret;
}
