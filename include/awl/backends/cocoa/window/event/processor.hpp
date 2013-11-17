#ifndef AWL_BACKENDS_COCOA_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_WINDOW_EVENT_PROCESSOR_HPP_INCLUDED

#include <awl/backends/cocoa/window/object_fwd.hpp>
#include <awl/backends/cocoa/window/event/AWLWindowDelegate.hpp>
#include <awl/window/event/destroy_signal.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/resize_signal.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/object.hpp>


namespace awl
{
namespace backends
{
namespace cocoa
{
namespace window
{
namespace event
{
class processor
:
	public awl::window::event::processor
{
FCPPT_NONCOPYABLE(
		processor);
public:
	explicit
	processor(
		cocoa::window::object &);

	bool
	poll();

	fcppt::signal::auto_connection
	destroy_callback(
		awl::window::event::destroy_callback const &);

	fcppt::signal::auto_connection
	resize_callback(
		awl::window::event::resize_callback const &);

	awl::window::object &
	window() const;

	void
	resize();

	void
	destroy();

	~processor();
private:
	cocoa::window::object &window_;
	awl::window::event::resize_signal resize_;
	awl::window::event::destroy_signal destroy_;
	__strong AWLWindowDelegate *delegate_;
};
}
}
}
}
}

#endif
