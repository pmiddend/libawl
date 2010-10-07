#ifndef AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
#include <awl/backends/x11/colormap_ptr.hpp>
#include <awl/backends/x11/class_hint.hpp>
#include <awl/backends/x11/size_hints.hpp>
#include <awl/backends/x11/wm_hints.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
class window_instance
:
	public awl::window::instance
{
public:
	explicit
	window_instance(
		display_ptr,
		awl::window::parameters const &);

	void
	show();

	~window_instance();
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

#endif