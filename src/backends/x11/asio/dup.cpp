#include <awl/backends/x11/asio/dup.hpp>
#include <awl/exception.hpp>
#include <fcppt/text.hpp>
#include <unistd.h>

int
awl::backends::x11::asio::dup(
	int const _fd
)
{
	int const ret(
		::dup(
			_fd
		)
	);

	if(
		ret == -1
	)
		throw awl::exception(
			FCPPT_TEXT("dup() failed!")
		);

	return ret;
}
