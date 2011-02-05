#ifndef AWL_BACKENDS_X11_ASIO_FD_WRAPPER_HPP_INCLUDED
#define AWL_BACKENDS_X11_ASIO_FD_WRAPPER_HPP_INCLUDED

#include <awl/backends/x11/asio/fd_wrapper_fwd.hpp>
#include <awl/backends/x11/asio/fd_flags_resetter.hpp>
#include <awl/backends/x11/asio/read_callback.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio/io_service.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace asio
{

class fd_wrapper
{
	FCPPT_NONCOPYABLE(
		fd_wrapper
	);
public:
	fd_wrapper(
		boost::asio::io_service &,
		awl::backends::x11::display_ptr
	);

	~fd_wrapper();

	void
	on_read(
		awl::backends::x11::asio::read_callback const &
	);
private:
	awl::backends::x11::asio::fd_flags_resetter fd_flags_resetter_;

	boost::asio::posix::stream_descriptor stream_wrapper_;
};

}
}
}
}

#endif
