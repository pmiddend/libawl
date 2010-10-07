#ifndef AWL_WINDOW_VECTOR_HPP_INCLUDED
#define AWL_WINDOW_VECTOR_HPP_INCLUDED

#include <awl/window/scalar.hpp>
#include <fcppt/math/vector/static.hpp>

namespace awl
{
namespace window
{
typedef
fcppt::math::vector::static_
<
	scalar,
	2
>::type
vector;
}
}

#endif
