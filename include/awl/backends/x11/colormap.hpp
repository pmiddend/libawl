#ifndef AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED
#define AWL_BACKENDS_X11_COLORMAP_HPP_INCLUDED

#include <X11/Xlib.h>
#include <awl/backends/x11/display_ptr.hpp>
#include <awl/backends/x11/visual_ptr.hpp>
#include <fcppt/noncopyable.hpp>

namespace awl
{
namespace backends
{
namespace x11
{
class colormap
{
FCPPT_NONCOPYABLE(colormap)
public:
	explicit
	colormap(
		display_ptr,
		int screen,
		visual_ptr
	);

	~colormap();

	Colormap &
	get();
private:
	display_ptr const display_;
	Colormap c_;
};
}
}
}

#endif
