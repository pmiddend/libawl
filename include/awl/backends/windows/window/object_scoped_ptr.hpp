#ifndef AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/windows/window/object_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

typedef fcppt::scoped_ptr<
		awl::backends::windows::window::object
> object_scoped_ptr;

}
}
}
}

#endif
