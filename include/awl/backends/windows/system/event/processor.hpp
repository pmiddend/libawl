#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/event/object_fwd.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/system/event/processor_fwd.hpp>
#include <awl/backends/windows/system/event/callback.hpp>
#include <awl/backends/windows/system/event/handle_callback.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace windows
{
namespace system
{
namespace event
{

class AWL_CLASS_SYMBOL processor
:
	public awl::system::event::processor
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
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::windows::event::type,
		awl::backends::windows::system::event::callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	register_handle_callback(
		awl::backends::windows::system::event::handle_callback const &
	) = 0;

	virtual
	awl::backends::windows::system::event::handle_unique_ptr
	create_event_handle() = 0;

	virtual
	void
	process(
		awl::backends::windows::event::object const &
	) = 0;

	virtual
	bool
	poll_handles() = 0;

	virtual
	void
	next() = 0;
};

}
}
}
}
}

#endif
