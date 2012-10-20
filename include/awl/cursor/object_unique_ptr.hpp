#ifndef AWL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_CURSOR_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/cursor/object_fwd.hpp>
#include <fcppt/unique_ptr_impl.hpp>


namespace awl
{
namespace cursor
{

typedef fcppt::unique_ptr<
	awl::cursor::object
> object_unique_ptr;

}
}

#endif
