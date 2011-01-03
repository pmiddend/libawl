#include <awl/mainloop/asio/create_io_service_base.hpp>
#include <awl/mainloop/asio/create_io_service.hpp>
#include <awl/mainloop/asio/io_service.hpp>
#include <awl/mainloop/io_service_ptr.hpp>

awl::mainloop::io_service_ptr const
awl::mainloop::asio::create_io_service_base()
{
	return
		asio::create_io_service();
}
