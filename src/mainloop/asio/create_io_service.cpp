#include <awl/mainloop/asio/create_io_service.hpp>
#include <awl/mainloop/asio/io_service_unique_ptr.hpp>
#include <awl/mainloop/asio/original_io_service.hpp>
#include <fcppt/make_unique_ptr.hpp>


awl::mainloop::asio::io_service_unique_ptr
awl::mainloop::asio::create_io_service()
{
	return
		awl::mainloop::asio::io_service_unique_ptr(
			fcppt::make_unique_ptr<
				mainloop::asio::original_io_service
			>()
		);
}
