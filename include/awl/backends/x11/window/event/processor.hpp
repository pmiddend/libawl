#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/window/event/processor_fwd.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/noncopyable.hpp>

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

class AWL_CLASS_SYMBOL processor
:
	public awl::window::event::processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_SYMBOL
	processor();
public:
	AWL_SYMBOL
	~processor();

	virtual fcppt::signal::auto_connection
	register_callback(
		int event_type,
		x11::window::event::callback const &
	) = 0;
};

}
}
}
}
}

#endif
