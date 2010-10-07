#ifndef AWL_BACKENDS_X11_VISUAL_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

namespace awl
{
namespace backends
{
namespace x11
{
class visual
{
FCPPT_NONCOPYABLE(visual)
public:
	// We take an optional XVisualInfo here because sometimes we get a
	// visual _and_ the corresponing info struct, which we must XFree
	// afterwards. If no info structure is defined, this class uses a
	// generic one.
	explicit
	visual(
		// We need the display for the info guessing
		Display *,
		Visual *,
		XVisualInfo * = 0);

	Visual *
	get() const;

	XVisualInfo *
	info() const;

	~visual();
private:
	Visual *ptr_;
	XVisualInfo *info_;
};
}
}
}

#endif
