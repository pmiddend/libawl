#ifndef AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/event_processor_fwd.hpp>
#include <awl/backends/x11/event_callback.hpp>
#include <awl/backends/x11/event_function.hpp>
#include <awl/backends/x11/window_instance_ptr.hpp>
#include <awl/event/processor.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/ptr_container/ptr_map.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

class event_processor
:
	public awl::event::processor
{
	FCPPT_NONCOPYABLE(
		event_processor
	)
public:
	explicit event_processor(
		x11::window_instance_ptr
	);

	~event_processor();

	void
	dispatch();

	fcppt::signal::auto_connection
	register_callback(
		int event_type,
		x11::event_callback const &
	);
private:
	x11::window_instance_ptr const window_;

	typedef fcppt::signal::object<
		x11::event_function
	> event_signal;

	typedef boost::ptr_map<
		int,
		event_signal
	> event_signal_map;

	event_signal_map signals_;
};

}
}
}

#endif
