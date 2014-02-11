#ifndef AWL_BACKENDS_X11_VISUAL_COPY_FROM_PARENT_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_COPY_FROM_PARENT_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/visual/object.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

class AWL_CLASS_SYMBOL copy_from_parent
:
	public awl::backends::x11::visual::object
{
	FCPPT_NONCOPYABLE(
		copy_from_parent
	);
public:
	AWL_SYMBOL
	copy_from_parent();

	AWL_SYMBOL
	~copy_from_parent()
	override;

	AWL_SYMBOL
	Visual *
	get() const
	override;

	AWL_SYMBOL
	XVisualInfo *
	info() const
	override;

	AWL_SYMBOL
	int
	depth() const
	override;
};

}
}
}
}

#endif
