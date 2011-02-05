#ifndef AWL_MAINLOOP_ASIO_IO_SERVICE_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_IO_SERVICE_HPP_INCLUDED

#include <awl/mainloop/asio/io_service_fwd.hpp>
#include <awl/mainloop/dispatcher_callback.hpp>
#include <awl/mainloop/io_service.hpp>
#include <awl/mainloop/nullary_callback.hpp>
#include <awl/system/object_ptr.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <boost/asio/io_service.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace mainloop
{
namespace asio
{

class AWL_CLASS_SYMBOL io_service
:
	public mainloop::io_service
{
	FCPPT_NONCOPYABLE(
		io_service
	);
protected:
	AWL_SYMBOL
	io_service();
public:
	AWL_SYMBOL
	virtual ~io_service();

	AWL_SYMBOL
	virtual boost::asio::io_service &
	get() = 0;

	void
	run_one();

	void
	run();

	void
	poll();

	void
	stop();

	void
	reset();

	void
	post(
		mainloop::nullary_callback const &
	);

	dispatcher_ptr const
	create_dispatcher(
		system::object_ptr,
		mainloop::dispatcher_callback const &
	);
};

}
}
}

#endif
