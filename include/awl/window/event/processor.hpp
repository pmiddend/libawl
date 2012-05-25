#ifndef AWL_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/event/close_callback_fwd.hpp>
#include <awl/window/event/focus_in_callback_fwd.hpp>
#include <awl/window/event/focus_out_callback_fwd.hpp>
#include <awl/window/event/destroy_callback_fwd.hpp>
#include <awl/window/event/processor_fwd.hpp>
#include <awl/window/event/resize_callback_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>


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
	virtual
	bool
	poll() = 0;

	virtual
	fcppt::signal::auto_connection
	close_callback(
		awl::window::event::close_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	destroy_callback(
		awl::window::event::destroy_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	focus_in_callback(
		awl::window::event::focus_in_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	focus_out_callback(
		awl::window::event::focus_out_callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	) = 0;

	virtual
	awl::window::object &
	window() const = 0;

	AWL_SYMBOL
	virtual
	~processor() = 0;
};

}
}
}

#endif
