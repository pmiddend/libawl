#ifndef AWL_BACKENDS_X11_WINDOW_SYSTEM_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_SYSTEM_HPP_INCLUDED

#include <awl/system/object.hpp>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
namespace system
{

class object
:
	public awl::system::object
{
	FCPPT_NONCOPYABLE(
		object
	)
public:
	// NOTE: We could add a string specifying which display to connect
	// to here
	AWL_SYMBOL
	object();

	AWL_SYMBOL
	~object();
	
	AWL_SYMBOL
	awl::window::instance_ptr const
	create(
		awl::window::parameters const &
	);

	AWL_SYMBOL
	x11::display_ptr const
	display() const;
private:
	x11::display_ptr const display_;
};

}
}
}
}

#endif
