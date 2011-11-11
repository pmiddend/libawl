#ifndef AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED
#define AWL_BACKENDS_X11_WINDOW_HOLDER_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/symbol.hpp>
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
		x11::display &,
		Window
	);

	AWL_SYMBOL
	~holder();

	Window
	get() const;
private:
	x11::display &display_;

	Window const window_;
};

}
}
}
}

#endif
