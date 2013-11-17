#ifndef AWL_SYSTEM_OBJECT_HPP_INCLUDED
#define AWL_SYSTEM_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/system/object_fwd.hpp>
#include <awl/visual/object_unique_ptr.hpp>
#include <awl/window/object_unique_ptr.hpp>
#include <awl/window/parameters_fwd.hpp>
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
	object();
public:
	virtual
	awl::window::object_unique_ptr
	create_window(
		awl::window::parameters const &
	) = 0;

	virtual
	awl::visual::object_unique_ptr
	default_visual() = 0;

	virtual
	awl::window::object_unique_ptr
	focus_window() = 0;

	AWL_SYMBOL
	virtual
	~object();
};

}
}

#endif
