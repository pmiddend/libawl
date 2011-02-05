#ifndef AWL_BACKENDS_X11_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_ORIGINAL_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/x11/window/common_instance.hpp>
#include <awl/backends/x11/window/original_class_hint.hpp>
#include <awl/backends/x11/colormap_ptr.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/size_hints.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
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
	public awl::backends::x11::window::common_instance
{
	FCPPT_NONCOPYABLE(
		original_instance
	);
public:
	AWL_SYMBOL
	explicit
	original_instance(
		x11::display_ptr,
		awl::window::parameters const &
	);

	AWL_SYMBOL
	~original_instance();

	AWL_SYMBOL
	x11::display_ptr const
	display() const;

	AWL_SYMBOL
	x11::screen const	
	screen() const;

	AWL_SYMBOL
	x11::visual_ptr const
	visual() const;

	AWL_SYMBOL
	Window
	get() const;
private:
	x11::display_ptr display_;

	x11::screen screen_;

	x11::visual_ptr visual_;

	x11::colormap_ptr colormap_;

	Window window_;

	x11::wm_hints wm_hints_;

	x11::size_hints size_hints_;

	x11::window::original_class_hint class_hint_;
};

}
}
}
}

#endif
