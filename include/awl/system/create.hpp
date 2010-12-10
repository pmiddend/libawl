#ifndef AWL_SYSTEM_CREATE_HPP_INCLUDED
#define AWL_SYSTEM_CREATE_HPP_INCLUDED

#include <awl/system/object_ptr.hpp>
#include <awl/symbol.hpp>

namespace awl
{
namespace system
{

// This function creates a window system that fits the current
// operating system/environment (will create the x11 system in Linux
// and the WinAPI system on windows)
AWL_SYMBOL
system::object_ptr const
create();

}
}

#endif
