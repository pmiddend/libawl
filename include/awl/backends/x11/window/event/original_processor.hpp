#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/window/event/processor.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/function.hpp>
#include <awl/backends/x11/window/instance_fwd.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/resize_function.hpp>
#include <awl/window/instance_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/connection_manager.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/unregister/base_decl.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <map>
#include <fcppt/config/external_end.hpp>

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
	);
public:
	AWL_SYMBOL
	explicit original_processor(
		x11::window::instance &
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	dispatch();

	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	);

	awl::window::instance &
	window() const;

	AWL_SYMBOL
	fcppt::signal::auto_connection
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

	x11::window::instance &window_;

	typedef fcppt::signal::object<
		x11::window::event::function,
		fcppt::signal::unregister::base
	> signal;

	typedef boost::ptr_map<
		int,
		signal
	> event_signal_map;

	typedef unsigned mask_count;

	typedef std::map<
		long,
		mask_count
	> mask_count_map;

	event_signal_map signals_;

	mask_count_map mask_counts_;

	long event_mask_;

	fcppt::signal::connection_manager const connection_manager_;

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
