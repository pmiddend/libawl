#ifndef AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{
class display
{
FCPPT_NONCOPYABLE(display)
public:
	explicit
	display();

	Display *
	get() const;

	~display();
private:
	Display * const ptr_;
};
}
}
}

#endif
