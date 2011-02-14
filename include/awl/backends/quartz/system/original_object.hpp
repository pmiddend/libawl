#ifndef AWL_BACKENDS_QUARTZ_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/quartz/system/object.hpp>
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

class original_object
:
	public awl::backends::quartz::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_SYMBOL
	original_object();

	AWL_SYMBOL
	~original_object();
	
	AWL_SYMBOL
	awl::window::instance_ptr const
	create(
		awl::window::parameters const &
	);
private:
	void * autorelease_pool_;
};

}
}
}
}

#endif
