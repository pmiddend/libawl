#ifndef AWL_BACKENDS_WINDOWS_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/callback.hpp>
#include <awl/backends/windows/window/event/return_type.hpp>
#include <awl/backends/windows/window/instance_ptr.hpp>
#include <awl/backends/windows/windows.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/resize_function.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/optional_impl.hpp>
#include <boost/ptr_container/ptr_map.hpp>

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
	)
public:
	AWL_SYMBOL
	explicit original_processor(
		windows::window::instance_ptr
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	dispatch();

	AWL_SYMBOL
	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	);

	AWL_SYMBOL
	awl::window::instance_ptr const
	window() const;

	AWL_SYMBOL
	fcppt::signal::auto_connection
	register_callback(
		UINT,
		windows::window::event::callback const &
	);

	AWL_SYMBOL
	windows::window::event::return_type const
	execute_callback(
		UINT msg,
		WPARAM wparam,
		LPARAM lparam
	);
private:
	windows::window::instance_ptr const window_;

	typedef fcppt::signal::object<
		windows::window::event::function
	> signal_type;

	typedef boost::ptr_map<
		UINT,
		signal_type
	> signal_map;

	signal_map signals_;

	typedef fcppt::signal::object<
		awl::window::event::resize_function
	> resize_signal;

	resize_signal resize_signal_;
};

}
}
}
}
}

#endif
