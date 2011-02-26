#ifndef AWL_BACKENDS_QUARTZ_EVENT_MANAGER_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_EVENT_MANAGER_HPP_INCLUDED

#include <awl/backends/quartz/window_ref.hpp>
#include <awl/symbol.hpp>
#include <map>
#include <queue>

namespace awl
{
namespace backends
{
namespace quartz
{

class event_manager
{
public:
	AWL_SYMBOL
	static void
	fetch_and_buffer_events();

	AWL_SYMBOL
	static bool
	dispatch_events_for_window(
		window_ref const
	);

private:
	typedef void * event_ref;
	typedef std::queue<
		event_ref
	> event_queue;

	typedef std::map<
		window_ref const,
		event_queue
	> window_event_map;
	static window_event_map event_buffer_;
};

}
}
}

#endif
