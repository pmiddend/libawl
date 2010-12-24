#ifndef AWL_MAINLOOP_IO_SERVICE_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_IO_SERVICE_PTR_HPP_INCLUDED

#include <awl/mainloop/io_service_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::shared_ptr<
	io_service
> io_service_ptr;

}
}

#endif
