#include <awl/backends/x11/asio_dispatcher.hpp>
#include <awl/backends/x11/display.hpp>
#include <fcppt/tr1/functional.hpp>
#include <boost/asio/buffer.hpp>
#include <X11/Xlib.h>
#include <X11/Xlibint.h>

awl::backends::x11::asio_dispatcher::asio_dispatcher(	
	boost::asio::io_service &_io_service,
	awl::backends::x11::display_ptr const _display,
	awl::mainloop::dispatcher_callback const &_callback
)
:
	display_(_display),
	io_service_(_io_service),
	stream_wrapper_(
		_io_service,
		_display->get()->fd
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
	if(
		::XPending(
			display_->get()
		)
		> 0
	)
	{
		io_service_.post(
			std::tr1::bind(
				&asio_dispatcher::on_post_finished,
				this
			)
		);
	}
	else
	{
		stream_wrapper_.async_read_some(
			boost::asio::null_buffers(),
			std::tr1::bind(
				&asio_dispatcher::on_select_finished,
				this,
				std::tr1::placeholders::_1
			)
		);
	}
}

void
awl::backends::x11::asio_dispatcher::on_select_finished(
	boost::system::error_code const &_error
)
{
	if(
		_error
	)
		return;
	
	on_post_finished();
}

void
awl::backends::x11::asio_dispatcher::on_post_finished()
{
	callback_();

	if(
		running_
	)
		register_handler();
}
