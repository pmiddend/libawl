#include <awl/mainloop/asio/create_io_service.hpp>
#include <awl/mainloop/asio/io_service.hpp>
#include <fcppt/make_shared_ptr.hpp>

awl::mainloop::io_service_ptr const
awl::mainloop::asio::create_io_service()
{
	return
		fcppt::make_shared_ptr<
			mainloop::asio::io_service
		>();
}
