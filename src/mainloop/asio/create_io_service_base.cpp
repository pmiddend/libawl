#include <awl/mainloop/asio/create_io_service_base.hpp>
#include <awl/mainloop/asio/create_io_service.hpp>
#include <awl/mainloop/asio/io_service.hpp>
#include <awl/mainloop/io_service_unique_ptr.hpp>

awl::mainloop::io_service_unique_ptr
awl::mainloop::asio::create_io_service_base()
{
	return
		awl::mainloop::io_service_unique_ptr(
			asio::create_io_service()
		);
}
