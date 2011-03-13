#ifndef AWL_MAINLOOP_IO_SERVICE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_IO_SERVICE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/mainloop/io_service_fwd.hpp>
#include <fcppt/unique_ptr.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::unique_ptr<
	mainloop::io_service
> io_service_unique_ptr;

}
}

#endif
