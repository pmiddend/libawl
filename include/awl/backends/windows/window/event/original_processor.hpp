#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/event/lparam.hpp>
#include <awl/backends/windows/event/message_fwd.hpp>
#include <awl/backends/windows/event/type.hpp>
#include <awl/backends/windows/event/wparam.hpp>
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/callback.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/backends/windows/window/instance_fwd.hpp>
#include <awl/window/event/close_callback.hpp>
#include <awl/window/event/close_signal.hpp>
#include <awl/window/event/destroy_callback.hpp>
#include <awl/window/event/destroy_signal.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/resize_signal.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/optional_impl.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <fcppt/config/external_end.hpp>

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

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::windows::window::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_SYMBOL
	explicit original_processor(
		windows::window::instance &
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	poll();

	AWL_SYMBOL
	fcppt::signal::auto_connection
	close_callback(
		awl::window::event::close_callback const &
	);

	AWL_SYMBOL
	fcppt::signal::auto_connection
	destroy_callback(
		awl::window::event::destroy_callback const &
	);

	AWL_SYMBOL
	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	);

	AWL_SYMBOL
	awl::window::instance &
	window() const;

	AWL_SYMBOL
	awl::backends::windows::window::instance &
	windows_window() const;

	AWL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		awl::backends::windows::event::type,
		windows::window::event::callback const &
	);

	void
	process(
		awl::backends::windows::event::message const &
	);

	awl::backends::windows::event::type const
	allocate_user_message();

	void
	free_user_message(
		awl::backends::windows::event::type
	);

	AWL_SYMBOL
	windows::window::event::return_type const
	execute_callback(
		awl::backends::windows::event::type,
		awl::backends::windows::event::wparam,
		awl::backends::windows::event::lparam
	);
private:
	void
	do_process(
		awl::backends::windows::event::message const &
	);

	windows::window::instance &window_;

	typedef fcppt::signal::object<
		windows::window::event::function
	> signal_type;

	typedef boost::ptr_map<
		awl::backends::windows::event::type,
		signal_type
	> signal_map;

	signal_map signals_;

	awl::window::event::close_signal close_signal_;

	awl::window::event::destroy_signal destroy_signal_;

	awl::window::event::resize_signal resize_signal_;
};

}
}
}
}
}

#endif
