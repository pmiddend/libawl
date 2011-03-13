#ifndef AWL_MAINLOOP_ASIO_CREATE_IO_SERVICE_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_CREATE_IO_SERVICE_HPP_INCLUDED

#include <awl/mainloop/asio/io_service_unique_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

AWL_SYMBOL
asio::io_service_unique_ptr
create_io_service();

}
}
}

#endif
