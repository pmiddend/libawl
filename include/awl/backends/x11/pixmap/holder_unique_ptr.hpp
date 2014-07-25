#ifndef AWL_BACKENDS_X11_PIXMAP_HOLDER_UNIQUE_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_PIXMAP_HOLDER_UNIQUE_PTR_HPP_INCLUDED

#include <awl/backends/x11/pixmap/holder_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace pixmap
{

typedef
std::unique_ptr<
	awl::backends::x11::pixmap::holder
>
holder_unique_ptr;

}
}
}
}

#endif
