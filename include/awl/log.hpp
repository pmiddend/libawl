#ifndef AWL_LOG_HPP_INCLUDED
#define AWL_LOG_HPP_INCLUDED

// Note that we are a bit wasteful in including all of the log headers here,
// but whenever you want this log you want all of the log functions -
// guaranteed
#include <fcppt/log/headers.hpp>
#include <fcppt/log/parameters/inherited.hpp>

namespace awl
{
/// This is the main logger, constituting the root of the logger tree.
fcppt::log::object &
log();
}

#endif
