#ifndef AWL_CURSOR_OBJECT_HPP_INCLUDED
#define AWL_CURSOR_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace cursor
{

class AWL_CLASS_SYMBOL object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_SYMBOL
	object();
public:
	AWL_SYMBOL
	virtual
	~object() = 0;
};

}
}

#endif
