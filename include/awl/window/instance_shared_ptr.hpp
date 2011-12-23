#ifndef AWL_WINDOW_INSTANCE_SHARED_PTR_HPP_INCLUDED
#define AWL_WINDOW_INSTANCE_SHARED_PTR_HPP_INCLUDED

#include <awl/window/instance_fwd.hpp>
#include <fcppt/shared_ptr_impl.hpp>

namespace awl
{
namespace window
{

typedef fcppt::shared_ptr<
	window::instance
> instance_shared_ptr;

}
}

#endif
