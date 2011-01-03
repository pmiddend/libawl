#ifndef AWL_BACKENDS_X11_ASIO_FCNTL_HPP_INCLUDED
#define AWL_BACKENDS_X11_ASIO_FCNTL_HPP_INCLUDED

namespace awl
{
namespace backends
{
namespace x11
{
namespace asio
{

int
fcntl(
	int fd,
	int cmd,
	int flags
);

}
}
}
}

#endif
