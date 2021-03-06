#ifndef AWL_WINDOW_OBJECT_HPP_INCLUDED
#define AWL_WINDOW_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/visual/object_fwd.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/rect_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace window
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
	void
	show() = 0;

	virtual
	awl::window::dim const
	size() const = 0;

	virtual
	awl::window::rect const
	rect() const = 0;

	virtual
	bool
	equal_to(
		awl::window::object const &
	) const = 0;

	virtual
	awl::visual::object const &
	visual() const = 0;

	AWL_SYMBOL
	virtual
	~object() = 0;
};

}
}

#endif
