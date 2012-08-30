#ifndef AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_SYSTEM_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/windows/event/object_fwd.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/system/event/callback.hpp>
#include <awl/backends/windows/system/event/handle_callback.hpp>
#include <awl/backends/windows/system/event/handle_function.hpp>
#include <awl/backends/windows/system/event/handle_unique_ptr.hpp>
#include <awl/backends/windows/system/event/original_processor_fwd.hpp>
#include <awl/backends/windows/system/event/object_fwd.hpp>
#include <awl/backends/windows/system/event/processor.hpp>
#include <awl/backends/windows/system/object_fwd.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/system/optional_exit_code.hpp>
#include <awl/system/event/quit_callback.hpp>
#include <awl/system/event/quit_signal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/container/raw_vector_decl.hpp>
#include <fcppt/signal/auto_connection_fwd.hpp>
#include <fcppt/signal/object_decl.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <fcppt/config/external_end.hpp>

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

class AWL_CLASS_SYMBOL original_processor
:
	public windows::system::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_SYMBOL
	explicit original_processor(
		windows::system::object &
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	poll();

	AWL_SYMBOL
	void
	quit(
		awl::main::exit_code
	);

	AWL_SYMBOL
	bool
	running() const;

	AWL_SYMBOL
	awl::main::exit_code const
	exit_code() const;

	AWL_SYMBOL
	fcppt::signal::auto_connection
	quit_callback(
		awl::system::event::quit_callback const &
	);

	AWL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::windows::event::type,
		windows::system::event::callback const &
	);

	AWL_SYMBOL
	fcppt::signal::auto_connection
	register_handle_callback(
		windows::system::event::handle_callback const &
	);

	AWL_SYMBOL
	system::event::handle_unique_ptr
	create_event_handle();

	AWL_SYMBOL
	void
	process(
		awl::backends::windows::event::object const &
	);

	AWL_SYMBOL
	bool
	poll_handles();

	AWL_SYMBOL
	void
	next();
private:
	void
	do_process(
		awl::backends::windows::event::type,
		awl::backends::windows::system::event::object const &
	);

	void
	on_quit(
		awl::backends::windows::system::event::object const &
	);

	template<
		typename Function
	>
	bool
	generic_multiple_wait(
		Function,
		DWORD timeout
	);

	void
	unregister_event_handle(
		HANDLE
	);

	typedef fcppt::signal::object<
		windows::system::event::function
	> signal_type;

	typedef boost::ptr_map<
		windows::event::type,
		signal_type
	> signal_map;

	signal_map signals_;

	typedef fcppt::signal::object<
		windows::system::event::handle_function
	> handle_signal;

	handle_signal handle_signal_;

	typedef fcppt::container::raw_vector<
		HANDLE
	> handle_vector;

	handle_vector handles_;

	awl::system::optional_exit_code exit_code_;

	awl::system::event::quit_signal quit_signal_;

	fcppt::signal::scoped_connection const quit_connection_;
};

}
}
}
}
}

#endif
