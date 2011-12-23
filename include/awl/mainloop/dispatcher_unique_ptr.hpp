#ifndef AWL_MAINLOOP_DISPATCHER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_DISPATCHER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/mainloop/dispatcher_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::unique_ptr<
	dispatcher
> dispatcher_unique_ptr;

}
}

#endif
