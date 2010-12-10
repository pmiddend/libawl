#ifndef AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/backends/x11/window/event/optional.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
#include <awl/window/instance.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_CLASS_SYMBOL instance
:
	public awl::window::instance
{
	FCPPT_NONCOPYABLE(
		instance
	)
protected:
	AWL_SYMBOL
	instance();
public:
	AWL_SYMBOL
	virtual ~instance();

	AWL_SYMBOL
	virtual display_ptr const
	display() const = 0;

	AWL_SYMBOL
	virtual int
	screen() const = 0;

	AWL_SYMBOL
	virtual visual_ptr const
	visual() const = 0;

	AWL_SYMBOL
	virtual Window
	get() const = 0;

	AWL_SYMBOL
	virtual x11::window::event::object const
	next_event() = 0;

	AWL_SYMBOL
	virtual x11::window::event::optional const
	poll_event(
		long event_mask
	) = 0;
};

}
}
}
}

#endif
