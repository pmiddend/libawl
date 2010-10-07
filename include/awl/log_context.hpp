#ifndef AWL_LOG_CONTEXT_HPP_INCLUDED
#define AWL_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/log/context_fwd.hpp>

namespace awl
{
/// The log_context() is a singleton (brrrr) to get the global log context. The
/// context is needed to access all awl's sub-loggers by a string so they can
/// be turned on and off easily.
fcppt::log::context &
log_context();
}

#endif
