#ifndef AWL_BACKENDS_X11_WRAPPED_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_WRAPPED_VISUAL_HPP_INCLUDED

#include <awl/backends/x11/visual.hpp>
#include <awl/backends/x11/visual_info_unique_ptr.hpp>
#include <awl/backends/x11/visual_info_scoped_ptr.hpp>
#include <awl/symbol.hpp>
#include <fcppt/scoped_ptr.hpp>
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

class wrapped_visual
:
	public x11::visual
{
	FCPPT_NONCOPYABLE(
		wrapped_visual
	);
public:
	AWL_SYMBOL
	wrapped_visual(
		Visual &,
		x11::visual_info_unique_ptr
	);

	AWL_SYMBOL
	virtual ~wrapped_visual();

	AWL_SYMBOL
	Visual &
	get() const;

	AWL_SYMBOL
	XVisualInfo &
	info() const;
private:
	Visual &visual_;

	x11::visual_info_scoped_ptr const info_;
};

}
}
}

#endif
