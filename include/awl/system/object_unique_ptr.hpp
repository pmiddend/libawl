#ifndef AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <fcppt/unique_ptr.hpp>

namespace awl
{
namespace system
{

typedef
fcppt::unique_ptr
<
	system::object
>
object_unique_ptr;

}
}

#endif
