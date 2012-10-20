#ifndef AWL_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/window/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace window
{

typedef fcppt::unique_ptr<
	awl::window::object
> object_unique_ptr;

}
}

#endif
