#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_OBJECT_PTR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_OBJECT_PTR_HPP_INCLUDED

#include <awl/backends/windows/system/object_fwd.hpp>
#include <fcppt/shared_ptr.hpp>

namespace awl
{
namespace backends
{
namespace windows
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
