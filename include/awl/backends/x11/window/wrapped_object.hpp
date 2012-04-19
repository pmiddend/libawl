#ifndef AWL_BACKENDS_X11_WINDOW_WRAPPED_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_WRAPPED_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/backends/x11/visual/object_scoped_ptr.hpp>
#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/backends/x11/window/common_object.hpp>
#include <awl/backends/x11/window/wrapped_class_hint.hpp>
#include <awl/backends/x11/window/event/optional.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters_fwd.hpp>
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

class AWL_CLASS_SYMBOL wrapped_object
:
	public awl::backends::x11::window::common_object
{
	FCPPT_NONCOPYABLE(
		wrapped_object
	);
public:
	AWL_SYMBOL
	wrapped_object(
		awl::backends::x11::display &,
		awl::backends::x11::screen,
		Window
	);

	AWL_SYMBOL
	~wrapped_object();

	AWL_SYMBOL
	void
	destroy();

	AWL_SYMBOL
	bool
	destroyed() const;

	AWL_SYMBOL
	awl::backends::x11::display &
	display() const;

	AWL_SYMBOL
	awl::backends::x11::screen const
	screen() const;

	AWL_SYMBOL
	awl::backends::x11::visual::object const &
	visual() const;

	AWL_SYMBOL
	Window
	get() const;

	AWL_SYMBOL
	awl::backends::x11::window::class_hint const *
	class_hint() const;
private:
	awl::backends::x11::display &display_;

	awl::backends::x11::screen const screen_;

	Window const window_;

	awl::backends::x11::visual::object_scoped_ptr const visual_;

	awl::backends::x11::window::wrapped_class_hint const class_hint_;
};

}
}
}
}

#endif
