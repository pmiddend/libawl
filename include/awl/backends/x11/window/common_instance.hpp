#ifndef AWL_BACKENDS_X11_WINDOW_COMMON_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_COMMON_INSTANCE_HPP_INCLUDED

#include <awl/backends/x11/window/instance.hpp>
#include <awl/window/dim.hpp>
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

class AWL_CLASS_SYMBOL common_instance
:
	public awl::backends::x11::window::instance
{
	FCPPT_NONCOPYABLE(
		common_instance
	)
protected:
	AWL_SYMBOL
	common_instance();
public:
	AWL_SYMBOL
	virtual ~common_instance();

	AWL_SYMBOL
	void
	show();

	AWL_SYMBOL
	awl::window::dim const
	size() const;
};

}
}
}
}

#endif
