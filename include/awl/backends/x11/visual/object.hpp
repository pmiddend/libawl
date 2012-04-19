#ifndef AWL_BACKENDS_X11_VISUAL_OBJECT_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_OBJECT_HPP_INCLUDED

#include <awl/backends/x11/visual/object_fwd.hpp>
#include <awl/visual/object.hpp>
#include <awl/symbol.hpp>
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

class object
:
	public awl::visual::object
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

	virtual
	Visual &
	get() const = 0;

	virtual
	XVisualInfo &
	info() const = 0;
};

}
}
}
}

#endif
