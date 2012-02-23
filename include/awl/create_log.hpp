#ifndef AWL_CREATE_LOG_HPP_INCLUDED
#define AWL_CREATE_LOG_HPP_INCLUDED

#include <fcppt/log/parameters/object_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>

namespace awl
{

fcppt::log::parameters::object const
create_log(
	fcppt::log::location const &
);

}

#endif
