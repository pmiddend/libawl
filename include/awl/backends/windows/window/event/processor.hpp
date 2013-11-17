#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/windows/event/message_fwd.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/window/object_fwd.hpp>
#include <awl/backends/windows/window/event/callback.hpp>
#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <awl/window/event/processor.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
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
	virtual
	~processor() = 0;

	virtual
	awl::backends::windows::window::object &
	windows_window() const = 0;

	virtual
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::windows::event::type,
		awl::backends::windows::window::event::callback const &
	) = 0;

	virtual
	void
	process(
		awl::backends::windows::event::message const &
	) = 0;

	virtual
	awl::backends::windows::event::type const
	allocate_user_message() = 0;

	virtual
	void
	free_user_message(
		awl::backends::windows::event::type
	) = 0;
};

}
}
}
}
}

#endif
