#ifndef AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/windows/window/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

typedef std::unique_ptr<
		awl::backends::windows::window::object
> object_unique_ptr;

}
}
}
}

#endif
