#ifndef AWL_WINDOW_OPTIONAL_POSITION_FWD_HPP_INCLUDED
#define AWL_WINDOW_OPTIONAL_POSITION_FWD_HPP_INCLUDED

#include <awl/window/vector.hpp>
#include <fcppt/optional_fwd.hpp>

namespace awl
{
namespace window
{

typedef fcppt::optional<
	awl::window::vector
> optional_position;

}
}

#endif
