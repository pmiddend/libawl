#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_SIGNAL_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/window/event/signal/unique_connection.hpp>
#include <awl/backends/x11/window/event/signal/unregister_callback.hpp>
#include <awl/backends/x11/window/event/callback.hpp>
#include <awl/backends/x11/window/event/function.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/signal/object.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{
namespace signal
{

class object
{
	FCPPT_NONCOPYABLE(
		object
	)
public:
	AWL_SYMBOL
	object();

	AWL_SYMBOL
	~object();

	AWL_SYMBOL
	signal::unique_connection
	connect(
		x11::window::event::callback const &,
		signal::unregister_callback const &
	);

	AWL_SYMBOL
	void
	operator()(
		x11::window::event::object const &
	) const;
private:
	typedef fcppt::signal::object<
		x11::window::event::function
	> event_signal;

	event_signal signal_;
};

}
}
}
}
}
}

#endif
