#ifndef AWL_BACKENDS_X11_WM_HINTS_HPP_INCLUDED
#define AWL_BACKENDS_X11_WM_HINTS_HPP_INCLUDED

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
class wm_hints 
{
FCPPT_NONCOPYABLE(wm_hints)
public:
	wm_hints();
	~wm_hints();
	XWMHints *get() const;
private:
	XWMHints *const hints;
};
}
}
}

#endif
