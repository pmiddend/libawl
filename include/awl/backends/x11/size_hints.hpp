#ifndef AWL_BACKENDS_X11_SIZE_HINTS_HPP_INCLUDED
#define AWL_BACKENDS_X11_SIZE_HINTS_HPP_INCLUDED

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
class size_hints 
{
	FCPPT_NONCOPYABLE(
		size_hints
	);
public:
	AWL_SYMBOL
	size_hints(
		int min_w,
		int min_h,
		int desired_w,
		int desired_h
	);

	AWL_SYMBOL
	~size_hints();

	AWL_SYMBOL
	XSizeHints *
	get() const;
private:
	XSizeHints *const hints;
};
}
}
}

#endif
