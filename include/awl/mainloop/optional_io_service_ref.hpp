#ifndef AWL_MAINLOOP_OPTIONAL_IO_SERVICE_REF_HPP_INCLUDED
#define AWL_MAINLOOP_OPTIONAL_IO_SERVICE_REF_HPP_INCLUDED

#include <awl/mainloop/io_service_fwd.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace mainloop
{

typedef fcppt::optional<
	awl::mainloop::io_service &
> optional_io_service_ref;

}
}

#endif
