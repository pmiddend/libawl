#ifndef AWL_BACKENDS_QUARTZ_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/quartz/system/event/processor.hpp>
#include <awl/backends/quartz/system/object_ptr.hpp>
#include <awl/class_symbol.hpp>
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
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::quartz::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_SYMBOL
	explicit original_processor(
		awl::backends::quartz::system::object_ptr
	);

	bool
	dispatch();

	AWL_SYMBOL
	~original_processor();
};

}
}
}
}
}

#endif
