#ifndef AWL_BACKENDS_X11_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/x11/event/object_fwd.hpp>
#include <awl/backends/x11/event/fd/callback_fwd.hpp>
#include <awl/backends/x11/event/fd/object.hpp>
#include <awl/backends/x11/event/fd/optional_duration_fwd.hpp>
#include <awl/backends/x11/system/event/processor_fwd.hpp>
#include <awl/backends/x11/system/event/callback.hpp>
#include <awl/backends/x11/system/event/opcode.hpp>
#include <awl/backends/x11/system/event/type.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/noncopyable.hpp>


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
	~processor();

	virtual
	fcppt::signal::auto_connection
	register_callback(
		x11::system::event::opcode const &,
		x11::system::event::type const &,
		x11::system::event::callback const &
	) = 0;

	virtual
	fcppt::signal::auto_connection
	register_fd_callback(
		awl::backends::x11::event::fd::object const &,
		awl::backends::x11::event::fd::callback const &
	) = 0;

	virtual
	bool
	epoll(
		awl::backends::x11::event::fd::optional_duration const &
	) = 0;

	virtual
	void
	process(
		x11::event::object const &
	) = 0;
};

}
}
}
}
}

#endif
