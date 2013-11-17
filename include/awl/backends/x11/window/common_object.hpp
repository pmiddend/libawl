#ifndef AWL_BACKENDS_X11_WINDOW_COMMON_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_COMMON_OBJECT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/window/class_hint_fwd.hpp>
#include <awl/backends/x11/window/object.hpp>
#include <awl/window/dim_fwd.hpp>
#include <awl/window/object_fwd.hpp>
#include <awl/window/rect_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class AWL_CLASS_SYMBOL common_object
:
	public awl::backends::x11::window::object
{
	FCPPT_NONCOPYABLE(
		common_object
	);
protected:
	AWL_SYMBOL
	common_object();
public:
	AWL_SYMBOL
	virtual
	~common_object();

	AWL_SYMBOL
	void
	show();

	AWL_SYMBOL
	awl::window::dim const
	size() const;

	AWL_SYMBOL
	awl::window::rect const
	rect() const;

	AWL_SYMBOL
	bool
	equal_to(
		awl::window::object const &
	) const;
};

}
}
}
}

#endif
