#ifndef AWL_BACKENDS_X11_ORIGINAL_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_ORIGINAL_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/event/optional.hpp>
#include <awl/backends/x11/window/event/object_fwd.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
#include <awl/backends/x11/colormap_ptr.hpp>
#include <awl/backends/x11/class_hint.hpp>
#include <awl/backends/x11/size_hints.hpp>
#include <awl/backends/x11/wm_hints.hpp>
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

class AWL_CLASS_SYMBOL original_instance
:
	public awl::backends::x11::window::instance
{
	FCPPT_NONCOPYABLE(
		original_instance
	)
public:
	AWL_SYMBOL
	explicit
	original_instance(
		display_ptr,
		awl::window::parameters const &
	);

	AWL_SYMBOL
	~original_instance();

	AWL_SYMBOL
	void
	show();

	AWL_SYMBOL
	awl::window::dim const
	size() const;

	AWL_SYMBOL
	display_ptr const
	display() const;

	AWL_SYMBOL
	int
	screen() const;

	AWL_SYMBOL
	visual_ptr const
	visual() const;

	AWL_SYMBOL
	Window
	get() const;

	AWL_SYMBOL
	x11::window::event::object const
	next_event();

	AWL_SYMBOL
	x11::window::event::optional const
	poll_event(
		long event_mask
	);
private:
	display_ptr display_;

	int screen_;

	visual_ptr visual_;

	colormap_ptr colormap_;

	Window window_;

	wm_hints wm_hints_;

	size_hints size_hints_;

	class_hint class_hint_;
};

}
}
}
}

#endif
