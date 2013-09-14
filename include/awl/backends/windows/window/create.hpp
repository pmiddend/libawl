#ifndef AWL_BACKENDS_WINDOWS_WINDOW_CREATE_HPP_INCLUDED
#define AWL_BACKENDS_WINDOWS_WINDOW_CREATE_HPP_INCLUDED

#include <awl/backends/windows/windows.hpp>
#include <awl/backends/windows/wndclass_fwd.hpp>
#include <awl/window/parameters_fwd.hpp>


namespace awl
{
namespace backends
{
namespace windows
{
namespace window
{

HWND
create(
	awl::window::parameters const &,
	awl::backends::windows::wndclass &
);

}
}
}
}


#endif
