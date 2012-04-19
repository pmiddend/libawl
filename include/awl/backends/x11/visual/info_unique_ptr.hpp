#ifndef AWL_BACKENDS_X11_VISUAL_INFO_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_VISUAL_INFO_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/deleter.hpp>
#include <fcppt/unique_ptr_impl.hpp>
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

typedef fcppt::unique_ptr<
	XVisualInfo,
	awl::backends::x11::deleter
> info_unique_ptr;

}
}
}
}

#endif
