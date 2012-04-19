#ifndef AWL_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace visual
{

class object
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
