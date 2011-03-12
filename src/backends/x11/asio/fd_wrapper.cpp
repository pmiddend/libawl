#include <awl/backends/x11/asio/fd_wrapper.hpp>
#include <awl/backends/x11/asio/dup.hpp>
#include <awl/backends/x11/display_fd.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/tr1/functional.hpp>
#include <boost/asio/buffer.hpp>

awl::backends::x11::asio::fd_wrapper::fd_wrapper(
	boost::asio::io_service &_io_service,
	awl::backends::x11::display &_display
)
:
	fd_flags_resetter_(
		_display
	),
	stream_wrapper_(
		_io_service,
		x11::asio::dup(
			x11::display_fd(
				_display
			)
		)
	)
{
}

awl::backends::x11::asio::fd_wrapper::~fd_wrapper()
{
}

void
awl::backends::x11::asio::fd_wrapper::on_read(
	awl::backends::x11::asio::read_callback const &_callback
)
{
	stream_wrapper_.async_read_some(
		boost::asio::null_buffers(),
		// asio needs placeholders for its internals to work
		std::tr1::bind(
			_callback,
			std::tr1::placeholders::_1
		)
	);
}
