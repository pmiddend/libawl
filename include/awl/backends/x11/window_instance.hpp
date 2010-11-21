#ifndef AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/event_fwd.hpp>
#include <awl/backends/x11/optional_event.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
#include <awl/window/instance.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{

class AWL_CLASS_SYMBOL window_instance
:
	public awl::window::instance
{
	FCPPT_NONCOPYABLE(
		window_instance
	)
protected:
	AWL_SYMBOL
	window_instance();
public:
	AWL_SYMBOL
	virtual ~window_instance();

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
	virtual x11::event const
	next_event() = 0;

	AWL_SYMBOL
	virtual x11::optional_event const
	poll_event(
		long event_mask
	) = 0;
};

}
}
}

#endif
