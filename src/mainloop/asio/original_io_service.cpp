#include <awl/mainloop/asio/original_io_service.hpp>

awl::mainloop::asio::original_io_service::original_io_service()
:
	mainloop::asio::io_service(),
	io_service_()
{
}

awl::mainloop::asio::original_io_service::~original_io_service()
{
}

boost::asio::io_service &
awl::mainloop::asio::original_io_service::get()
{
	return io_service_;
}
