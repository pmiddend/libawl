#include <awl/backends/cocoa/from_fcppt_string.hpp>
#include <Cocoa/Cocoa.h>

NSString *
awl::backends::cocoa::from_fcppt_string(
	fcppt::string const &s)
{
	return [NSString stringWithUTF8String:s.c_str()];
}
