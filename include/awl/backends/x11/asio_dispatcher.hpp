#ifndef AWL_BACKENDS_X11_ASIO_DISPATCHER_HPP_INCLUDED
#define AWL_BACKENDS_X11_ASIO_DISPATCHER_HPP_INCLUDED

#include <awl/mainloop/dispatcher.hpp>
#include <awl/mainloop/dispatcher_callback.hpp>
#include <awl/symbol.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/asio/posix/stream_descriptor.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/system/error_code.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

class asio_dispatcher
:
	public mainloop::dispatcher
{
	FCPPT_NONCOPYABLE(
		asio_dispatcher
	)
public:
	AWL_SYMBOL
	explicit asio_dispatcher(	
		boost::asio::io_service &,
		int fd,
		awl::mainloop::dispatcher_callback const &
	);

	AWL_SYMBOL
	~asio_dispatcher();
private:
	void
	stop();

	void
	register_handler();

	void
	callback(
		boost::system::error_code const &
	);

	boost::asio::posix::stream_descriptor stream_wrapper_;

	awl::mainloop::dispatcher_callback const callback_;

	bool running_;
};

}
}
}

#endif
