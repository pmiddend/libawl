#ifndef AWL_BACKENDS_QUARTZ_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_BACKENDS_QUARTZ_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/window/instance.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace quartz
{
namespace window
{

class AWL_CLASS_SYMBOL instance
:
	public awl::window::instance
{
	FCPPT_NONCOPYABLE(
		instance
	);
protected:
	AWL_SYMBOL
	instance();
public:
	AWL_SYMBOL
	virtual ~instance();

	AWL_SYMBOL
	virtual void *
	get() const = 0;
};

}
}
}
}

#endif
