#ifndef AWL_BACKENDS_X11_CURSOR_HOLDER_SCOPED_PTR_HPP_INCLUDED
#define AWL_BACKENDS_X11_CURSOR_HOLDER_SCOPED_PTR_HPP_INCLUDED

#include <awl/backends/x11/cursor/holder_fwd.hpp>
#include <fcppt/scoped_ptr_impl.hpp>


namespace awl
{
namespace backends
{
namespace x11
{
namespace cursor
{

typedef fcppt::scoped_ptr<
	awl::backends::x11::cursor::holder
> holder_scoped_ptr;

}
}
}
}

#endif
