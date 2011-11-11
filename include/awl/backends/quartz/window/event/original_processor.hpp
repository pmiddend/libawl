#ifndef AWL_BACKENDS_QUARTZ_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_WINDOW_EVENT_ORIGINAL_PROCESSOR_HPP_INCLUDED

#include <awl/backends/quartz/window/event/processor.hpp>
#include <awl/backends/quartz/window/instance_fwd.hpp>
#include <awl/window/event/resize_callback.hpp>
#include <awl/window/event/resize_function.hpp>
#include <awl/window/instance_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace window
{
namespace event
{

class AWL_CLASS_SYMBOL original_processor
:
	public awl::backends::quartz::window::event::processor
{
	FCPPT_NONCOPYABLE(
		original_processor
	);
public:
	AWL_SYMBOL
	explicit original_processor(
		quartz::window::instance &
	);

	AWL_SYMBOL
	~original_processor();

	AWL_SYMBOL
	bool
	dispatch();

	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &
	);

	awl::window::instance &
	window() const;
private:
	quartz::window::instance &window_;

	fcppt::signal::object<
		awl::window::event::resize_function
	> resize_signal_;
};

}
}
}
}
}

#endif
