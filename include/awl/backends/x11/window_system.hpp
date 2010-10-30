#ifndef AWL_BACKENDS_X11_WINDOW_SYSTEM_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_SYSTEM_HPP_INCLUDED

#include <awl/window/system.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

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
	FCPPT_NONCOPYABLE(
		window_system
	)
public:
	// NOTE: We could add a string specifying which display to connect
	// to here
	AWL_SYMBOL
	explicit
	window_system();

	AWL_SYMBOL
	~window_system();
	
	AWL_SYMBOL
	awl::window::instance_ptr const
	create(
		awl::window::parameters const &
	);
private:
	x11::display_ptr const display_;
};
}
}
}

#endif
