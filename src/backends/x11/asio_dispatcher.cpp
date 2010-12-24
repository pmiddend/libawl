#include <awl/backends/x11/asio_dispatcher.hpp>
#include <fcppt/tr1/functional.hpp>
#include <boost/asio/buffer.hpp>

#include <iostream>

awl::backends::x11::asio_dispatcher::asio_dispatcher(	
	boost::asio::io_service &_io_service,
	int const _fd,
	awl::mainloop::dispatcher_callback const &_callback
)
:
	stream_wrapper_(
		_io_service,
		_fd
	),
	callback_(
		_callback
	),
	running_(
		true
	)
{
	register_handler();
}

awl::backends::x11::asio_dispatcher::~asio_dispatcher()
{}

void
awl::backends::x11::asio_dispatcher::stop()
{
	running_ = false;
}

void
awl::backends::x11::asio_dispatcher::register_handler()
{
	std::cout << "register\n";

	stream_wrapper_.async_read_some(
		boost::asio::null_buffers(),
		std::tr1::bind(
			&asio_dispatcher::callback,
			this,
			std::tr1::placeholders::_1
		)
	);
}

void
awl::backends::x11::asio_dispatcher::callback(
	boost::system::error_code const &_error
)
{
	std::cout << "callback\n";

	if(
		_error
	)
		return;

	callback_();

#if 0
	if(
		running_
	)
		register_handler();
#endif
}
