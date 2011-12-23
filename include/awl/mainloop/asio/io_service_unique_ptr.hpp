#ifndef AWL_MAINLOOP_ASIO_IO_SERVICE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_IO_SERVICE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/mainloop/asio/io_service_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

typedef fcppt::unique_ptr<
	asio::io_service
> io_service_unique_ptr;

}
}
}

#endif
