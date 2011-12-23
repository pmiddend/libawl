#ifndef AWL_SYSTEM_OBJECT_SCOPED_PTR_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_SCOPED_PTR_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>

namespace awl
{
namespace system
{

typedef
fcppt::scoped_ptr
<
	system::object
>
object_scoped_ptr;

}
}

#endif
