#ifndef AWL_CURSOR_HOTSPOT_FWD_HPP_INCLUDED
#define AWL_CURSOR_HOTSPOT_FWD_HPP_INCLUDED

#include <awl/cursor/size.hpp>
#include <fcppt/math/vector/static.hpp>


namespace awl
{
namespace cursor
{

typedef
fcppt::math::vector::static_<
	awl::cursor::size,
	2
>
hotspot;

}
}

#endif
