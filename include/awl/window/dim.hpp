#ifndef AWL_WINDOW_DIM_HPP_INCLUDED
#define AWL_WINDOW_DIM_HPP_INCLUDED

#include <awl/window/scalar.hpp>
#include <fcppt/math/dim/static.hpp>

namespace awl
{
namespace window
{
typedef
fcppt::math::dim::static_
<
	scalar,
	2
>::type
dim;
}
}

#endif
