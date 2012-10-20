#ifndef AWL_BACKENDS_X11_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <awl/backends/x11/cursor/object_fwd.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

typedef fcppt::optional<
	awl::backends::x11::cursor::object const &
> const_optional_object_ref;

}
}
}
}

#endif
