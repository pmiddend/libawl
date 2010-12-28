#ifndef AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_DISPLAY_HPP_INCLUDED

#include <awl/class_symbol.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{

class AWL_CLASS_SYMBOL display
{
	FCPPT_NONCOPYABLE(
		display
	)
protected:
	AWL_SYMBOL
	display();
public:
	virtual Display *
	get() const = 0;

	AWL_SYMBOL
	virtual ~display();

	AWL_SYMBOL
	void
	sync(
		bool discard
	);
};

}
}
}

#endif
