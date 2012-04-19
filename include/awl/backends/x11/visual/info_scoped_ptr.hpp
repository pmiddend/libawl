#ifndef AWL_BACKENDS_X11_VISUAL_INFO_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_INFO_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/x11/deleter.hpp>
#include <fcppt/scoped_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/Xutil.h>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace visual
{

typedef fcppt::scoped_ptr<
	XVisualInfo,
	awl::backends::x11::deleter
> info_scoped_ptr;

}
}
}
}

#endif
