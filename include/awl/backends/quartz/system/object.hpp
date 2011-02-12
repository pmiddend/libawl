#ifndef AWL_BACKENDS_QUARTZ_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/backends/quartz/system/object_fwd.hpp>
#include <awl/system/object.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace system
{

class object
:
	public awl::system::object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_SYMBOL
	object();
public:
	AWL_SYMBOL
	virtual ~object();
};

}
}
}
}

#endif
