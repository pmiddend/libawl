#ifndef AWL_MAINLOOP_IO_SERVICE_SHARED_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_IO_SERVICE_SHARED_PTR_HPP_INCLUDED

#include <awl/mainloop/io_service_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::shared_ptr<
	mainloop::io_service
> io_service_shared_ptr;

}
}

#endif
