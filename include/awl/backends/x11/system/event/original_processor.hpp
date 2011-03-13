#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/map_key.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/backends/x11/system/object_fwd.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
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
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::x11::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_SYMBOL
	explicit original_processor(
		x11::system::object &
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	dispatch();

	fcppt::signal::auto_connection
	register_callback(
		x11::system::event::opcode const &,
		x11::system::event::type const &,
		x11::system::event::callback const &
	);
private:
	x11::system::object &system_;

	typedef fcppt::signal::object<
		event::function
	> signal;

	typedef boost::ptr_map<
		event::map_key,
		signal
	> event_signal_map;

	event_signal_map signals_;
};

}
}
}
}
}

#endif
