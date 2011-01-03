#ifndef AWL_MAINLOOP_ASIO_CREATE_IO_SERVICE_BASE_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_CREATE_IO_SERVICE_BASE_HPP_INCLUDED

#include <awl/mainloop/io_service_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

AWL_SYMBOL
mainloop::io_service_ptr const
create_io_service_base();

}
}
}

#endif
