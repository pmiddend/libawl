#ifndef AWL_BACKENDS_WINDOWS_WINDOW_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <awl/backends/windows/window/object_fwd.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

typedef
fcppt::optional<
	awl::backends::windows::window::object const &
>
const_optional_object_ref;

}
}
}
}

#endif
