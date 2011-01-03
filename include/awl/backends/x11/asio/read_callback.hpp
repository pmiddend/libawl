#ifndef AWL_BACKENDS_X11_ASIO_READ_CALLBACK_HPP_INCLUDED
#define AWL_BACKENDS_X11_ASIO_READ_CALLBACK_HPP_INCLUDED

#include <fcppt/function/object_fwd.hpp>
#include <boost/system/error_code.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace asio
{

typedef fcppt::function::object<
	void (
		boost::system::error_code const &
	)
> read_callback;

}
}
}
}

#endif
