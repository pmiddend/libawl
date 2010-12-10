#ifndef AWL_SYSTEM_OBJECT_PTR_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_PTR_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace system
{

typedef
fcppt::shared_ptr
<
	system::object
>
object_ptr;

}
}

#endif
