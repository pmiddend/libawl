#ifndef AWL_BACKENDS_X11_VISUAL_WRAPPED_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_WRAPPED_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <awl/backends/x11/visual/info_unique_ptr.hpp>
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

class AWL_CLASS_SYMBOL wrapped
:
	public awl::backends::x11::visual::object
{
	FCPPT_NONCOPYABLE(
		wrapped
	);
public:
	AWL_SYMBOL
	explicit
	wrapped(
		awl::backends::x11::visual::info_unique_ptr &&
	);

	AWL_SYMBOL
	~wrapped()
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
private:
	awl::backends::x11::visual::info_unique_ptr const info_;
};

}
}
}
}

#endif
