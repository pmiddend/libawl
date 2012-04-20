#ifndef AWL_BACKENDS_WINDOWS_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_VISUAL_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/windows/visual/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace visual
{

typedef fcppt::unique_ptr<
	awl::backends::windows::visual::object
> object_unique_ptr;

}
}
}
}

#endif
