#ifndef AWL_WINDOW_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <awl/window/object_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace window
{

typedef fcppt::scoped_ptr<
	window::object
> object_scoped_ptr;

}
}

#endif
