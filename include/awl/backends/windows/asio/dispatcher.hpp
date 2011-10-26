#ifndef AWL_BACKENDS_WINDOWS_ASIO_DISPATCHER_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_ASIO_DISPATCHER_HPP_INCLUDED

#include <awl/mainloop/dispatcher.hpp>
#include <awl/mainloop/dispatcher_callback.hpp>
#include <awl/symbol.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/asio/io_service.hpp>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace asio
{

class dispatcher
:
	public mainloop::dispatcher
{
	FCPPT_NONCOPYABLE(
		dispatcher
	);
public:
	AWL_SYMBOL
	explicit dispatcher(
		boost::asio::io_service &,
		awl::mainloop::dispatcher_callback const &
	);

	AWL_SYMBOL
	~dispatcher();
private:
	void
	stop();

	bool
	is_stopped() const;

	void
	register_handler();

	bool running_;

	boost::asio::io_service &io_service_;

	awl::mainloop::dispatcher_callback const callback_;
};

}
}
}
}

#endif
