#ifndef AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/signal/unique_connection.hpp>
#include <awl/backends/x11/event_callback.hpp>
#include <awl/event/processor.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

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
protected:
	AWL_SYMBOL
	event_processor();
public:
	AWL_SYMBOL
	~event_processor();

	virtual x11::signal::unique_connection
	register_callback(
		int event_type,
		x11::event_callback const &
	) = 0;
};

}
}
}

#endif
