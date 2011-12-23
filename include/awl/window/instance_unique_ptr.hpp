#ifndef AWL_WINDOW_INSTANCE_UNIQUE_PTR_HPP_INCLUDED
#define AWL_WINDOW_INSTANCE_UNIQUE_PTR_HPP_INCLUDED

#include <awl/window/instance_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>

namespace awl
{
namespace window
{

typedef fcppt::unique_ptr<
	window::instance
> instance_unique_ptr;

}
}

#endif
