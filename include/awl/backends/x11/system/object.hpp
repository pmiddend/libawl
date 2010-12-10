#ifndef AWL_BACKENDS_X11_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/system/object_fwd.hpp>
#include <awl/backends/x11/display_ptr.hpp>
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

class object
:
	public awl::system::object
{
	FCPPT_NONCOPYABLE(
		object
	)
protected:
	AWL_SYMBOL
	object();
public:
	AWL_SYMBOL
	~object();
	
	virtual x11::display_ptr const
	display() const = 0;
};

}
}
}
}

#endif
