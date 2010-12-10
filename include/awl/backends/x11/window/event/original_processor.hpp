#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/function.hpp>
#include <awl/backends/x11/window/event/signal/unique_connection.hpp>
#include <awl/backends/x11/window/event/signal/connection_manager.hpp>
#include <awl/backends/x11/window/event/signal/object.hpp>
#include <awl/backends/x11/window/instance_ptr.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/resize_function.hpp>
#include <awl/window/instance_ptr.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <map>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::x11::window::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	)
public:
	AWL_SYMBOL
	explicit original_processor(
		x11::window::instance_ptr
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	void
	dispatch();

	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	);

	awl::window::instance_ptr const
	window() const;

	AWL_SYMBOL
	x11::window::event::signal::unique_connection
	register_callback(
		int event_type,
		x11::window::event::callback const &
	);
private:
	void
	unregister(
		int event_type
	);

	void
	on_configure(
		x11::window::event::object const &
	);

	x11::window::instance_ptr const window_;

	typedef boost::ptr_map<
		int,
		window::event::signal::object
	> event_signal_map;

	typedef unsigned mask_count;

	typedef std::map<
		long,
		mask_count
	> mask_count_map;

	event_signal_map signals_;

	mask_count_map mask_counts_;

	long event_mask_;

	x11::window::event::signal::connection_manager const connection_manager_;

	fcppt::signal::object<
		awl::window::event::resize_function
	> resize_signal_;
};

}
}
}
}
}

#endif
