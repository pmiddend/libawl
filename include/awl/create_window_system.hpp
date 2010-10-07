#ifndef AWL_CREATE_WINDOW_SYSTEM_HPP_INCLUDED
#define AWL_CREATE_WINDOW_SYSTEM_HPP_INCLUDED

#include <awl/window/system_ptr.hpp>

namespace awl
{
// This function creates a window system that fits the current
// operating system/environment (will create the x11 system in Linux
// and the WinAPI system on windows)
window::system_ptr const
create_window_system();
}

#endif
