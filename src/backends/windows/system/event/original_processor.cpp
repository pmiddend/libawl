#include <awl/backends/windows/system/event/original_processor.hpp>

awl::backends::windows::system::event::original_processor::original_processor(
	windows::system::object_ptr
)
{
}

awl::backends::windows::system::event::original_processor::~original_processor()
{
}

bool
awl::backends::windows::system::event::original_processor::dispatch()
{
	return false;
}
