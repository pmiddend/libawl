#ifndef AWL_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED
#define AWL_CURSOR_CONST_OPTIONAL_OBJECT_REF_FWD_HPP_INCLUDED

#include <awl/cursor/object_fwd.hpp>
#include <fcppt/optional_fwd.hpp>


namespace awl
{
namespace cursor
{

typedef fcppt::optional<
	awl::cursor::object const &
> const_optional_object_ref;

}
}

#endif
