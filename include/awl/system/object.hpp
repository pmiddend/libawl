#ifndef AWL_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/system/object_fwd.hpp>
#include <awl/window/instance_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace system
{

class AWL_CLASS_SYMBOL object
{
	FCPPT_NONCOPYABLE(
		object
	);
protected:
	AWL_SYMBOL
	explicit
	object();
public:
	virtual window::instance_unique_ptr
	create(
		window::parameters const &
	) = 0;

	AWL_SYMBOL
	virtual
	~object();
};

}
}

#endif
