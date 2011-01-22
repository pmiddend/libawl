#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/system/event/processor_fwd.hpp>
#include <awl/backends/windows/system/event/callback.hpp>
#include <awl/backends/windows/system/event/handle_callback.hpp>
#include <awl/backends/windows/system/event/handle_ptr.hpp>
#include <awl/backends/windows/windows.hpp>
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
	)
protected:
	AWL_SYMBOL
	processor();
public:
	AWL_SYMBOL
	~processor();

	virtual
	fcppt::signal::auto_connection
	register_callback(
		UINT,
		windows::system::event::callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	register_handle_callback(
		windows::system::event::handle_callback const &
	) = 0;

	virtual
	system::event::handle_ptr const
	create_event_handle() = 0;
};

}
}
}
}
}

#endif
