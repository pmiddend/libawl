#ifndef AWL_BACKENDS_X11_ASIO_DISPATCHER_HPP_INCLUDED
#define AWL_BACKENDS_X11_ASIO_DISPATCHER_HPP_INCLUDED

#include <awl/backends/x11/asio/fd_wrapper_fwd.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/mainloop/dispatcher.hpp>
#include <awl/mainloop/dispatcher_callback.hpp>
#include <awl/symbol.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/system/error_code.hpp>

namespace awl
{
namespace backends
{
namespace x11
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
		awl::backends::x11::display_ptr,
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

	void
	on_select_finished(
		boost::system::error_code const &
	);

	void
	on_post_finished();

	awl::backends::x11::display_ptr const display_;

	boost::asio::io_service &io_service_;

	fcppt::scoped_ptr<
		awl::backends::x11::asio::fd_wrapper
	> fd_wrapper_;

	awl::mainloop::dispatcher_callback const callback_;
};

}
}
}
}

#endif
