#ifndef AWL_BACKENDS_X11_VISUAL_INFO_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_INFO_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/deleter.hpp>
#include <fcppt/unique_ptr.hpp>
#include <X11/Xutil.h>

namespace awl
{
namespace backends
{
namespace x11
{

typedef fcppt::unique_ptr<
	XVisualInfo,
	x11::deleter
> visual_info_unique_ptr;

}
}
}

#endif
