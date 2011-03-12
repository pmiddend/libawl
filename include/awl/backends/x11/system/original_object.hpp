#ifndef AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_ORIGINAL_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/system/object.hpp>
#include <awl/backends/x11/original_display.hpp>
#include <awl/system/object.hpp>
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

class original_object
:
	public awl::backends::x11::system::object
{
	FCPPT_NONCOPYABLE(
		original_object
	);
public:
	// NOTE: We could add a string specifying which display to connect
	// to here
	AWL_SYMBOL
	original_object();

	AWL_SYMBOL
	~original_object();
	
	AWL_SYMBOL
	awl::window::instance_ptr const
	create(
		awl::window::parameters const &
	);

	AWL_SYMBOL
	x11::display &
	display();
private:
	x11::original_display display_;
};

}
}
}
}

#endif
