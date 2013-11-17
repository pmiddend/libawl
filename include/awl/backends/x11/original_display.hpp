#ifndef AWL_BACKENDS_X11_ORIGINAL_DISPLAY_HPP_INCLUDED
#define AWL_BACKENDS_X11_ORIGINAL_DISPLAY_HPP_INCLUDED

#include <awl/symbol.hpp>
#include <awl/backends/x11/display.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


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
