#ifndef AWL_WINDOW_DIM_FWD_HPP_INCLUDED
#define AWL_WINDOW_DIM_FWD_HPP_INCLUDED

#include <awl/window/scalar.hpp>
#include <fcppt/math/dim/static.hpp>


namespace awl
{
namespace window
{

typedef
fcppt::math::dim::static_
<
	awl::window::scalar,
	2
>
dim;

}
}

#endif
