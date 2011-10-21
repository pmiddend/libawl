#include <awl/backends/x11/display.hpp>
#include <awl/backends/x11/asio/dispatcher.hpp>
#include <awl/backends/x11/asio/fd_wrapper.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/ref.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


awl::backends::x11::asio::dispatcher::dispatcher(
	boost::asio::io_service &_io_service,
	awl::backends::x11::display &_display,
	awl::mainloop::dispatcher_callback const &_callback
)
:
	display_(_display),
	io_service_(_io_service),
	fd_wrapper_(
		fcppt::make_unique_ptr<
			x11::asio::fd_wrapper
		>(
			fcppt::ref(
				_io_service
			),
			fcppt::ref(
				_display
			)
		)
	),
	callback_(
		_callback
	)
{
	this->register_handler();
}

awl::backends::x11::asio::dispatcher::~dispatcher()
{
}

void
awl::backends::x11::asio::dispatcher::stop()
{
	fd_wrapper_.reset();
}

bool
awl::backends::x11::asio::dispatcher::is_stopped() const
{
	return !fd_wrapper_;
}

void
awl::backends::x11::asio::dispatcher::register_handler()
{
	if(
		::XPending(
			display_.get()
		)
		> 0
	)
		io_service_.post(
			std::tr1::bind(
				&asio::dispatcher::on_post_finished,
				this
			)
		);
	else
		fd_wrapper_->on_read(
			std::tr1::bind(
				&asio::dispatcher::on_select_finished,
				this,
				std::tr1::placeholders::_1
			)
		);
}

void
awl::backends::x11::asio::dispatcher::on_select_finished(
	boost::system::error_code const &_error
)
{
	if(
		_error
	)
		return;

	this->on_post_finished();
}

void
awl::backends::x11::asio::dispatcher::on_post_finished()
{
	callback_();

	if(
		fd_wrapper_
	)
		this->register_handler();
}
