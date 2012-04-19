#ifndef AWL_VISUAL_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define AWL_VISUAL_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <awl/visual/object_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>


namespace awl
{
namespace visual
{

typedef fcppt::scoped_ptr<
	awl::visual::object
> object_scoped_ptr;

}
}

#endif
