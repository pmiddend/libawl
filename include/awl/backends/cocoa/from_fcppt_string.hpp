#ifndef AWL_BACKENDS_COCOA_FROM_FCPPT_STRING_HPP_INCLUDED
#define AWL_BACKENDS_COCOA_FROM_FCPPT_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>

@class NSString;

namespace awl
{
namespace backends
{
namespace cocoa
{
NSString *
from_fcppt_string(
	fcppt::string const &);
}
}
}

#endif
