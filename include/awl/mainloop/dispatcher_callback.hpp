#ifndef AWL_MAINLOOP_DISPATCHER_CALLBACK_HPP_INCLUDED
#define AWL_MAINLOOP_DISPATCHER_CALLBACK_HPP_INCLUDED

#include <fcppt/function/object_fwd.hpp>

namespace awl
{
namespace mainloop
{

typedef fcppt::function::object<
	bool ()
> dispatcher_callback;

}
}

#endif
