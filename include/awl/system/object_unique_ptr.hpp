#ifndef AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_UNIQUE_PTR_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace system
{

typedef
std::unique_ptr
<
	awl::system::object
>
object_unique_ptr;

}
}

#endif
