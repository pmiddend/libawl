#ifndef AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED

#include <awl/backends/x11/display_fwd.hpp>
#include <awl/backends/x11/screen.hpp>
#include <awl/backends/x11/visual/object_fwd.hpp>
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

class colormap
{
	FCPPT_NONCOPYABLE(
		colormap
	);
public:
	AWL_SYMBOL
	colormap(
		awl::backends::x11::display &,
		awl::backends::x11::screen,
		awl::backends::x11::visual::object const &
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
	awl::backends::x11::display &display_;

	Colormap colormap_;
};

}
}
}

#endif
