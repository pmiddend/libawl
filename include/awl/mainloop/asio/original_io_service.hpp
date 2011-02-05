#ifndef AWL_MAINLOOP_ASIO_ORIGINAL_IO_SERVICE_HPP_INCLUDED
#define AWL_MAINLOOP_ASIO_ORIGINAL_IO_SERVICE_HPP_INCLUDED

#include <awl/mainloop/asio/io_service.hpp>
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

class AWL_CLASS_SYMBOL original_io_service
:
	public mainloop::asio::io_service
{
	FCPPT_NONCOPYABLE(
		original_io_service
	);
public:
	AWL_SYMBOL
	original_io_service();

	AWL_SYMBOL
	~original_io_service();

	AWL_SYMBOL
	boost::asio::io_service &
	get();
private:
	boost::asio::io_service io_service_;
};

}
}
}

#endif
