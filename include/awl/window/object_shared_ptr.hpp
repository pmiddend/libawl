#ifndef AWL_WINDOW_OBJECT_SHARED_PTR_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_SHARED_PTR_HPP_INCLUDED

#include <awl/window/object_fwd.hpp>
#include <fcppt/shared_ptr_impl.hpp>

namespace awl
{
namespace window
{

typedef fcppt::shared_ptr<
	window::object
> object_shared_ptr;

}
}

#endif
