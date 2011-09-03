#include <awl/backends/windows/asio/dispatcher.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/asio/io_service.hpp>
#include <fcppt/config/external_end.hpp>

awl::backends::windows::asio::dispatcher::dispatcher(
	boost::asio::io_service &_io_service,
	awl::mainloop::dispatcher_callback const &_callback
)
:
	running_(true),
	io_service_(_io_service),
	callback_(_callback)
{
	register_handler();
}

awl::backends::windows::asio::dispatcher::~dispatcher()
{
}

void
awl::backends::windows::asio::dispatcher::stop()
{
	running_ = false;
}

bool
awl::backends::windows::asio::dispatcher::is_stopped() const
{
	return !running_;
}

void
awl::backends::windows::asio::dispatcher::register_handler()
{
	// this is just a hack to make the dispatcher work with windows, too

	if(
		!running_
	)
		return;

	callback_();

	io_service_.post(
		std::tr1::bind(
			&windows::asio::dispatcher::register_handler,
			this
		)
	);
}
