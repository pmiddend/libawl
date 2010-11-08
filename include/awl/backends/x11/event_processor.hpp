#ifndef AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/event_processor_fwd.hpp>
#include <awl/backends/x11/event_callback.hpp>
#include <awl/backends/x11/event_function.hpp>
#include <awl/backends/x11/window_instance_ptr.hpp>
#include <awl/backends/x11/signal/unique_connection.hpp>
#include <awl/backends/x11/signal/connection_manager.hpp>
#include <awl/backends/x11/signal/object.hpp>
#include <awl/event/processor.hpp>
#include <awl/event/resize_callback.hpp>
#include <awl/event/resize_function.hpp>
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

class AWL_CLASS_SYMBOL event_processor
:
	public awl::event::processor
{
	FCPPT_NONCOPYABLE(
		event_processor
	)
public:
	AWL_SYMBOL
	explicit event_processor(
		x11::window_instance_ptr
	);

	AWL_SYMBOL
	~event_processor();

	AWL_SYMBOL
	void
	dispatch();

	fcppt::signal::auto_connection
	resize_callback(
		awl::event::resize_callback const &
	);

	AWL_SYMBOL
	x11::signal::unique_connection
	register_callback(
		int event_type,
		x11::event_callback const &
	);
private:
	void
	unregister(
		int event_type
	);

	void
	on_configure(
		x11::event const &
	);

	void
	on_resize(
		x11::event const &
	);

	x11::window_instance_ptr const window_;

	typedef boost::ptr_map<
		int,
		signal::object
	> event_signal_map;

	typedef unsigned mask_count;

	typedef std::map<
		long,
		mask_count
	> mask_count_map;

	event_signal_map signals_;

	mask_count_map mask_counts_;

	long event_mask_;

	x11::signal::connection_manager const connection_manager_;

	fcppt::signal::object<
		awl::event::resize_function
	> resize_signal_;
};

}
}
}

#endif
