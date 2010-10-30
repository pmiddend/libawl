#ifndef AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED

#include <awl/symbol.hpp>
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
	FCPPT_NONCOPYABLE(
		display
	)
public:
	AWL_SYMBOL
	explicit
	display();

	AWL_SYMBOL
	Display *
	get() const;

	AWL_SYMBOL
	~display();

	AWL_SYMBOL
	void
	sync();
private:
	Display * const ptr_;
};

}
}
}

#endif
