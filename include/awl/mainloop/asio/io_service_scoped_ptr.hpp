#ifndef AWL_MAINLOOP_ASIO_IO_SERVICE_SCOPED_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_IO_SERVICE_SCOPED_PTR_HPP_INCLUDED

#include <awl/mainloop/asio/io_service_fwd.hpp>
#include <fcppt/scoped_ptr.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

typedef fcppt::scoped_ptr<
	asio::io_service
> io_service_scoped_ptr;

}
}
}

#endif
