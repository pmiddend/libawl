#ifndef AWL_MAINLOOP_ASIO_IO_SERVICE_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_IO_SERVICE_PTR_HPP_INCLUDED

#include <awl/mainloop/asio/io_service_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

typedef fcppt::shared_ptr<
	asio::io_service
> io_service_ptr;

}
}
}

#endif
