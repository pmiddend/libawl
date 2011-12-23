#ifndef AWL_WINDOW_INSTANCE_SCOPED_PTR_HPP_INCLUDED
#define AWL_WINDOW_INSTANCE_SCOPED_PTR_HPP_INCLUDED

#include <awl/window/instance_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace window
{

typedef fcppt::scoped_ptr<
	window::instance
> instance_scoped_ptr;

}
}

#endif
