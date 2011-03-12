#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/x11/window/common_instance.hpp>
#include <awl/backends/x11/window/hints.hpp>
#include <awl/backends/x11/window/holder.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <awl/backends/x11/window/size_hints.hpp>
#include <awl/backends/x11/colormap.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

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
	public awl::backends::x11::window::common_instance
{
	FCPPT_NONCOPYABLE(
		original_instance
	);
public:
	AWL_SYMBOL
	explicit
	original_instance(
		x11::display &,
		awl::window::parameters const &
	);

	AWL_SYMBOL
	~original_instance();

	AWL_SYMBOL
	x11::display &
	display() const;

	AWL_SYMBOL
	x11::screen const	
	screen() const;

	AWL_SYMBOL
	x11::visual &
	visual() const;

	AWL_SYMBOL
	Window
	get() const;
private:
	x11::display &display_;

	x11::screen const screen_;
	
	x11::visual const visual_;

	x11::colormap const colormap_;

	x11::window::hints const hints_;

	x11::window::size_hints const size_hints_;

	x11::window::original_class_hint const class_hint_;

	x11::window::holder const window_;
};

}
}
}
}

#endif
