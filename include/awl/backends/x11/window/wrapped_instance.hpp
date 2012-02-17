#ifndef AWL_BACKENDS_X11_WINDOW_WRAPPED_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_WRAPPED_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/backends/x11/window/common_instance.hpp>
#include <awl/backends/x11/window/wrapped_class_hint.hpp>
#include <awl/backends/x11/window/event/optional.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual_scoped_ptr.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>

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
	public awl::backends::x11::window::common_instance
{
	FCPPT_NONCOPYABLE(
		wrapped_instance
	);
public:
	AWL_SYMBOL
	explicit
	wrapped_instance(
		x11::display &,
		x11::screen,
		Window
	);

	AWL_SYMBOL
	~wrapped_instance();

	AWL_SYMBOL
	void
	destroy();

	AWL_SYMBOL
	bool
	destroyed() const;

	AWL_SYMBOL
	x11::display &
	display() const;

	AWL_SYMBOL
	x11::screen const
	screen() const;

	AWL_SYMBOL
	x11::visual const &
	visual() const;

	AWL_SYMBOL
	Window
	get() const;

	AWL_SYMBOL
	x11::window::class_hint const *
	class_hint() const;
private:
	x11::display &display_;

	x11::screen const screen_;

	Window const window_;

	x11::visual_scoped_ptr const visual_;

	x11::window::wrapped_class_hint const class_hint_;
};

}
}
}
}

#endif
