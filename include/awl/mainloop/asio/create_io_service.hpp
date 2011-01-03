#ifndef AWL_MAINLOOP_ASIO_CREATE_IO_SERVICE_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_CREATE_IO_SERVICE_HPP_INCLUDED

#include <awl/mainloop/asio/io_service_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

AWL_SYMBOL
asio::io_service_ptr const
create_io_service();

}
}
}

#endif
