#ifndef AWL_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/event/processor_fwd.hpp>
#include <awl/event/resize_callback.hpp>
#include <awl/window/instance_ptr.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace event
{

class AWL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	)
protected:
	AWL_SYMBOL
	processor();
public:
	virtual void
	dispatch() = 0;

	virtual fcppt::signal::auto_connection
	resize_callback(
		event::resize_callback const &
	) = 0;

	virtual awl::window::instance_ptr const
	window() const = 0;

	AWL_SYMBOL
	virtual ~processor();
};

}
}

#endif
