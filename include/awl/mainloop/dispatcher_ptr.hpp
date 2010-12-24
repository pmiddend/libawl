#ifndef AWL_MAINLOOP_DISPATCHER_PTR_HPP_INCLUDED
#define AWL_MAINLOOP_DISPATCHER_PTR_HPP_INCLUDED

#include <awl/mainloop/dispatcher_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::shared_ptr<
	dispatcher
> dispatcher_ptr;

}
}

#endif
