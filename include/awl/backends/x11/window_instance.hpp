#ifndef AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/backends/x11/window_instance_fwd.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
#include <awl/backends/x11/colormap_ptr.hpp>
#include <awl/backends/x11/class_hint.hpp>
#include <awl/backends/x11/size_hints.hpp>
#include <awl/backends/x11/wm_hints.hpp>
#include <awl/backends/x11/optional_event.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

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
	FCPPT_NONCOPYABLE(
		window_instance
	)
public:
	AWL_SYMBOL
	explicit
	window_instance(
		display_ptr,
		awl::window::parameters const &
	);

	AWL_SYMBOL
	~window_instance();

	AWL_SYMBOL
	void
	show();

	AWL_SYMBOL
	window::dim const
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
	optional_event const
	next_event();

	AWL_SYMBOL
	optional_event const
	peek_event();
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
