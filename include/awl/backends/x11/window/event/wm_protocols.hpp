#ifndef AWL_BACKENDS_X11_WINDOW_EVENT_WM_PROTOCOLS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_EVENT_WM_PROTOCOLS_HPP_INCLUDED

#include <awl/backends/x11/window/instance_fwd.hpp>
#include <awl/backends/x11/window/event/atom_vector.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{
namespace event
{

class wm_protocols
{
	FCPPT_NONCOPYABLE(
		wm_protocols
	);
public:
	wm_protocols(
		awl::backends::x11::window::instance &,
		awl::backends::x11::window::event::atom_vector const &
	);

	~wm_protocols();
private:
	// TODO: unset what was given here again!
};

}
}
}
}
}

#endif
