#ifndef AWL_WINDOW_INSTANCE_PTR_HPP_INCLUDED
#define AWL_WINDOW_INSTANCE_PTR_HPP_INCLUDED

#include <awl/window/instance_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace window
{
typedef
fcppt::shared_ptr
<
	instance
>
instance_ptr;
}
}

#endif
