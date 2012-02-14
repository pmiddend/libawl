#ifndef AWL_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/instance_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace window
{
namespace event
{

class AWL_CLASS_SYMBOL processor
{
	FCPPT_NONCOPYABLE(
		processor
	);
protected:
	AWL_SYMBOL
	processor();
public:
	virtual bool
	poll() = 0;

	virtual fcppt::signal::auto_connection
	close_callback(
		event::close_callback const &
	) = 0;

	virtual fcppt::signal::auto_connection
	destroy_callback(
		event::destroy_callback const &
	) = 0;

	virtual fcppt::signal::auto_connection
	resize_callback(
		event::resize_callback const &
	) = 0;

	virtual awl::window::instance &
	window() const = 0;

	AWL_SYMBOL
	virtual ~processor() = 0;
};

}
}
}

#endif
