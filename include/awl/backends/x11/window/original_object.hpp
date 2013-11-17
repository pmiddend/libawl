#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/backends/x11/window/common_object.hpp>
#include <awl/backends/x11/window/hints.hpp>
#include <awl/backends/x11/window/holder.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <awl/backends/x11/window/size_hints.hpp>
#include <awl/window/object.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_CLASS_SYMBOL original_object
:
	public awl::backends::x11::window::common_object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	AWL_SYMBOL
	original_object(
		awl::backends::x11::display &,
		awl::backends::x11::screen,
		awl::window::parameters const &
	);

	AWL_SYMBOL
	~original_object();

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

	awl::backends::x11::visual::object const &visual_;

	awl::backends::x11::colormap const colormap_;

	awl::backends::x11::window::hints const hints_;

	awl::backends::x11::window::size_hints const size_hints_;

	awl::backends::x11::window::original_class_hint const class_hint_;

	awl::backends::x11::window::holder window_;
};

}
}
}
}

#endif
