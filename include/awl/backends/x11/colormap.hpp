#ifndef AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED

#include <X11/Xlib.h>
#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual_fwd.hpp>
#include <awl/symbol.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

class colormap
{
	FCPPT_NONCOPYABLE(
		colormap
	);
public:
	AWL_SYMBOL
	explicit
	colormap(
		x11::display &,
		x11::screen,
		x11::visual const &
	);

	AWL_SYMBOL
	~colormap();

	AWL_SYMBOL
	Colormap &
	get();

	AWL_SYMBOL
	Colormap const &
	get() const;
private:
	x11::display &display_;

	Colormap colormap_;
};

}
}
}

#endif
