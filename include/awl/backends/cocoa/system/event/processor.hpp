#ifndef AWL_BACKENDS_COCOA_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/system/event/processor.hpp>
#include <fcppt/noncopyable.hpp>

@class NSApplication;

namespace awl
{
namespace backends
{
namespace cocoa
{
namespace system
{
namespace event
{
class processor
:
	public awl::system::event::processor
{
FCPPT_NONCOPYABLE(
	processor);
public:
	explicit
	processor();

	bool
	poll();

	~processor();
private:
	NSApplication *app_;
};
}
}
}
}
}

#endif
