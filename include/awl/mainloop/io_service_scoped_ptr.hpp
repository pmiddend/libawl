#ifndef AWL_MAINLOOP_IO_SERVICE_SCOPED_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_IO_SERVICE_SCOPED_PTR_HPP_INCLUDED

#include <awl/mainloop/io_service_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::scoped_ptr<
	mainloop::io_service
> io_service_scoped_ptr;

}
}

#endif
