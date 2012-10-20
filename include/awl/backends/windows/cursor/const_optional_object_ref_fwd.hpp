#ifndef AWL_BACKENDS_WINDOWS_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <awl/backends/windows/cursor/object_fwd.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

typedef fcppt::optional<
	awl::backends::windows::cursor::object const &
> const_optional_object_ref;

}
}
}
}

#endif
