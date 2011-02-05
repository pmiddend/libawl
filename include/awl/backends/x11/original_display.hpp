#ifndef AWL_BACKENDS_X11_ORIGINAL_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_ORIGINAL_DISPLAY_HPP_INCLUDED

#include <awl/backends/x11/display.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{

class original_display
:
	public awl::backends::x11::display
{
	FCPPT_NONCOPYABLE(
		original_display
	);
public:
	AWL_SYMBOL
	original_display();

	AWL_SYMBOL
	Display *
	get() const;

	AWL_SYMBOL
	~original_display();
private:
	Display *const ptr_;
};

}
}
}

#endif
