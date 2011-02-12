#ifndef AWL_BACKENDS_QUARTZ_SYSTEM_OBJECT_PTR_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_SYSTEM_OBJECT_PTR_HPP_INCLUDED

#include <awl/backends/quartz/system/object_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace system
{

typedef fcppt::shared_ptr<
	system::object
> object_ptr;

}
}
}
}

#endif
