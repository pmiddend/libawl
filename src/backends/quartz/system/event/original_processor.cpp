#include <awl/backends/quartz/system/event/original_processor.hpp>
#include <awl/backends/quartz/event_manager.hpp>

awl::backends::quartz::system::event::original_processor::original_processor(
	quartz::system::object_ptr const _system
)
{
}

awl::backends::quartz::system::event::original_processor::~original_processor()
{
}

bool
awl::backends::quartz::system::event::original_processor::dispatch()
{
	return awl::backends::quartz::event_manager::dispatch_events_for_window(NULL);
}
