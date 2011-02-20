#ifndef AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED

#include <awl/backends/x11/display_ptr.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <X11/Xlib.h>

namespace awl
{
namespace backends
{
namespace x11
{
namespace window
{

class holder
{
	FCPPT_NONCOPYABLE(
		holder
	);
public:
	AWL_SYMBOL
	explicit holder(
		x11::display_ptr,
		Window
	);

	AWL_SYMBOL
	~holder();

	Window
	get() const;
private:
	x11::display_ptr const display_;

	Window const window_;
};

}
}
}
}

#endif
