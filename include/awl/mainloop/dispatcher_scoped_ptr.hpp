#ifndef AWL_MAINLOOP_DISPATCHER_SCOPED_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_DISPATCHER_SCOPED_PTR_HPP_INCLUDED

#include <awl/mainloop/dispatcher_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::scoped_ptr<
	dispatcher
> dispatcher_scoped_ptr;

}
}

#endif
