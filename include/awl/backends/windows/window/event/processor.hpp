#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/window/event/processor_fwd.hpp>
#include <awl/backends/windows/window/event/callback.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/window/event/processor.hpp>
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
	)
protected:
	AWL_SYMBOL
	processor();
public:
	AWL_SYMBOL virtual
	~processor();

	virtual fcppt::signal::auto_connection
	register_callback(
		UINT,
		windows::window::event::callback const &
	) = 0;
};

}
}
}
}
}

#endif
