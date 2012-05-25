#ifndef AWL_BACKENDS_LINUX_FD_OBJECT_VECTOR_HPP_INCLUDED
#define AWL_BACKENDS_LINUX_FD_OBJECT_VECTOR_HPP_INCLUDED

#include <awl/backends/linux/fd/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace linux
{
namespace fd
{

typedef std::vector<
	awl::backends::linux::fd::object
> object_vector;

}
}
}
}

#endif
