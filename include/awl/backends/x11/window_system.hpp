#ifndef AWL_BACKENDS_X11_WINDOW_SYSTEM_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_SYSTEM_HPP_INCLUDED

#include <awl/window/system.hpp>
#include <awl/backends/x11/display_ptr.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
class window_system
:
	public awl::window::system
{
public:
	// NOTE: We could add a string specifying which display to connect
	// to here
	explicit
	window_system();
	
	awl::window::instance_ptr const
	create(
		awl::window::parameters const &);
private:
	display_ptr display_;
};
}
}
}

#endif
