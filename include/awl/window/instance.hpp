#ifndef AWL_WINDOW_INSTANCE_HPP_INCLUDED
#define AWL_WINDOW_INSTANCE_HPP_INCLUDED

#include <awl/window/dim.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace window
{

class AWL_CLASS_SYMBOL instance
{
	FCPPT_NONCOPYABLE(
		instance
	);
protected:
	AWL_SYMBOL
	explicit
	instance();
public:
	virtual void
	show() = 0;

	virtual window::dim const
	size() const = 0;

	AWL_SYMBOL
	virtual ~instance();
};

}
}

#endif
