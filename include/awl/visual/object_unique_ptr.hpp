#ifndef AWL_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/visual/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace visual
{

typedef fcppt::unique_ptr<
	awl::visual::object
> object_unique_ptr;

}
}

#endif
