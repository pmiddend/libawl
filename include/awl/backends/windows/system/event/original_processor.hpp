#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/system/event/original_processor_fwd.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/system/object_ptr.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public windows::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	)
public:
	AWL_SYMBOL
	explicit original_processor(
		windows::system::object_ptr
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	dispatch();
};

}
}
}
}
}

#endif
