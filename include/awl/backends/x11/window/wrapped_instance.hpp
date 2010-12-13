#ifndef AWL_BACKENDS_X11_WINDOW_WRAPPED_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_WRAPPED_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/x11/window/instance.hpp>
#include <awl/backends/x11/window/event/optional.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
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

class AWL_CLASS_SYMBOL wrapped_instance
:
	public awl::backends::x11::window::instance
{
	FCPPT_NONCOPYABLE(
		wrapped_instance
	)
public:
	AWL_SYMBOL
	explicit
	wrapped_instance(
		display_ptr,
		int screen,
		Window window
	);

	AWL_SYMBOL
	~wrapped_instance();

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
private:
	x11::display_ptr const display_;

	int const screen_;

	Window const window_;
};

}
}
}
}

#endif
