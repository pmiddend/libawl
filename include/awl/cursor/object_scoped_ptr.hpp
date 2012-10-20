#ifndef AWL_CURSOR_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define AWL_CURSOR_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <awl/cursor/object_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>


namespace awl
{
namespace cursor
{

typedef fcppt::scoped_ptr<
	awl::cursor::object
> object_scoped_ptr;

}
}

#endif
