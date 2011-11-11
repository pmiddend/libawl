#ifndef AWL_BACKENDS_X11_VISUAL_INFO_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_INFO_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/x11/deleter.hpp>
#include <fcppt/scoped_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>

namespace awl
{
namespace backends
{
namespace x11
{

typedef fcppt::scoped_ptr<
	XVisualInfo,
	x11::deleter
> visual_info_scoped_ptr;

}
}
}

#endif
