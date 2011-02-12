#include <awl/backends/quartz/asio/dispatcher.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <boost/asio/io_service.hpp>

awl::backends::quartz::asio::dispatcher::dispatcher(
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

awl::backends::quartz::asio::dispatcher::~dispatcher()
{
}

void
awl::backends::quartz::asio::dispatcher::stop()
{
	running_ = false;
}

bool
awl::backends::quartz::asio::dispatcher::is_stopped() const
{
	return !running_;
}

void
awl::backends::quartz::asio::dispatcher::register_handler()
{
	// this is just a hack to make the dispatcher work with quartz, too
	// FIXME Also, this is copiepasted from the windows backend...

	if(
		!running_
	)
		return;

	callback_();

	io_service_.post(
		std::tr1::bind(
			&quartz::asio::dispatcher::register_handler,
			this
		)
	);
}
