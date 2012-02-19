#ifndef AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_SYSTEM_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/event/processor_fwd.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>


namespace awl
{
namespace system
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
	void
	quit(
		awl::main::exit_code
	) = 0;

	virtual
	bool
	running() const = 0;

	virtual
	awl::main::exit_code const
	exit_code() const = 0;

	virtual
	fcppt::signal::auto_connection
	quit_callback(
		awl::system::event::quit_callback const &
	) = 0;

	AWL_SYMBOL
	virtual ~processor();
};

}
}
}

#endif
