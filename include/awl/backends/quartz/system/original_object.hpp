#ifndef AWL_BACKENDS_QUARTZ_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/quartz/window_ref.hpp>
#include <awl/backends/quartz/system/object.hpp>
#include <awl/system/object.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <map>
#include <queue>

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
	void
	event_loop();

	typedef void * autorelease_pool_ref;
	autorelease_pool_ref const autorelease_pool_;
};

}
}
}
}

#endif
