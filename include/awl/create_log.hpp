#ifndef AWL_CREATE_LOG_HPP_INCLUDED
#define AWL_CREATE_LOG_HPP_INCLUDED

#include <fcppt/log/parameters/all_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>

namespace awl
{

fcppt::log::parameters::all const
create_log(
	fcppt::log::location const &
);

}

#endif
