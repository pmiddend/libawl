#ifndef AWL_BACKENDS_WINDOWS_CURSOR_DIM_FWD_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_CURSOR_DIM_FWD_HPP_INCLUDED

#include <awl/backends/windows/cursor/size.hpp>
#include <fcppt/math/dim/static.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace cursor
{

typedef
fcppt::math::dim::static_<
	awl::backends::windows::cursor::size,
	2
>
dim;

}
}
}
}

#endif
