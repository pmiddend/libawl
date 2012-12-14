#ifndef AWL_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/visual/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace visual
{

typedef std::unique_ptr<
	awl::visual::object
> object_unique_ptr;

}
}

#endif
